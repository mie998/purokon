// import from
// http://beet-aizu.hatenablog.com/entry/2019/03/12/171221
// モノイド上の単位元を決める、二項演算を決める、初期値をvectorで用意しておく、queryを求められた形に直す

// うし木(一点更新区間取得) : 0-indexed
// min 更新 RMQ の例
// auto f = [](int a, int b) { return min(a, b); };
// SegmentTree<int, decltype(f)> seg(f, UNIT);
// seg.build(vector<int>(n, INIT));
template <typename T, typename F>
struct SegmentTree {
    // using F = function<T(T, T)>;
    int n;
    F f;  // モノイド上の二項演算
    T ti; // モノイド上の単位元
    vector<T> dat;
    SegmentTree(){};
    SegmentTree(F f, T ti) : f(f), ti(ti) {}

    void init(int n_) {
        n = 1;
        while (n < n_)
            n <<= 1;
        dat.assign(n << 1, ti);
    }
    // v は要素の初期値で埋める(__INT_MAX__とかが基本)
    void build(const vector<T> &v) {
        int n_ = v.size();
        init(n_);
        for (int i = 0; i < n_; i++)
            dat[n + i] = v[i];
        for (int i = n - 1; i; i--)
            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }
    // k: index, x: value
    void set_val(int k, T x) {
        dat[k += n] = x;
        while (k >>= 1)
            dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
    }
    // 探索範囲は半開区間 [a,b)
    T query(int a, int b) {
        T vl = ti, vr = ti;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, dat[l++]);
            if (r & 1) vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }
};

// 遅延セグ木(区間更新区間取得) : 0-indexed
// SegmentTree<int, int, decltype(f), decltype(g), decltype(h)> seg(f,g,h,ti,ei);
template <typename T, typename E, typename F, typename G, typename H>
struct SegmentTree {
    // using F = function<T(T, T)>;
    // using G = function<T(T, E)>;
    // using H = function<E(E, E)>;
    int n, height;
    F f;
    G g;
    H h;
    T ti;
    E ei;
    vector<T> dat;
    vector<E> laz;
    SegmentTree(F f, G g, H h, T ti, E ei) : f(f), g(g), h(h), ti(ti), ei(ei) {}

    void init(int n_) {
        n = 1;
        height = 0;
        while (n < n_)
            n <<= 1, height++;
        dat.assign(2 * n, ti);
        laz.assign(2 * n, ei);
    }

    void build(const vector<T> &v) {
        int n_ = v.size();
        init(n_);
        for (int i = 0; i < n_; i++)
            dat[n + i] = v[i];
        for (int i = n - 1; i; i--)
            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    inline T reflect(int k) {
        return laz[k] == ei ? dat[k] : g(dat[k], laz[k]);
    }

    inline void eval(int k) {
        if (laz[k] == ei) return;
        laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
        laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
        dat[k] = reflect(k);
        laz[k] = ei;
    }

    inline void thrust(int k) {
        for (int i = height; i; i--)
            eval(k >> i);
    }

    inline void recalc(int k) {
        while (k >>= 1)
            dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
    }

    void update(int a, int b, E x) {
        thrust(a += n);
        thrust(b += n - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) laz[l] = h(laz[l], x), l++;
            if (r & 1) --r, laz[r] = h(laz[r], x);
        }
        recalc(a);
        recalc(b);
    }

    void set_val(int a, T x) {
        thrust(a += n);
        dat[a] = x;
        laz[a] = ei;
        recalc(a);
    }
    // 探索範囲は半開区間 [a,b)
    T query(int a, int b) {
        thrust(a += n);
        thrust(b += n - 1);
        T vl = ti, vr = ti;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, reflect(l++));
            if (r & 1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }
};

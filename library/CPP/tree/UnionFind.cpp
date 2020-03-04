// https://qiita.com/drken/items/cce6fc5c579051e64fab
// UnionFind<int> uf(n);
template <class Abel>
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> size;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n);
        rank.resize(n);
        size.resize(n);
        diff_weight.resize(n);
        for (int i = 0; i < n; ++i)
            par[i] = i, rank[i] = 0, size[i] = 1, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]]; // path compression
            return par[x] = r;
        }
    }
    // returns size of connected-tree number
    int get_size(int x) {
        return size[root(x)];
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool is_same(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        size[x] = size[y] = size[x] + size[y];
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

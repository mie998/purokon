const double PI = 3.1415926535;
// Cooley–Tukey FFT algorithm
// https://www.creativ.xyz/fast-fourier-transform/
// a[0] = b[0] = 0 とするのを忘れずに。
vector<complex<double>> fft(vector<complex<double>> a, bool inverse = false) {
    int n = a.size();
    int h = 0; // h = log_2(n)
    for (int i = 0; 1 << i < n; i++)
        h++;
    // バタフライ演算用の配置入れ替え
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (int k = 0; k < h; k++)
            j |= (i >> k & 1) << (h - 1 - k);
        if (i < j) swap(a[i], a[j]);
    }
    // バタフライ演算
    for (int b = 1; b < n; b *= 2) {
        // 第 log_2(b) + 1 段
        // ブロックサイズ = b * 2
        for (int j = 0; j < b; j++) {
            // ブロック内 j 個目
            // 重み w = (1 の原始 2b 乗根の j 乗)
            complex<double> w =
                polar(1.0, (2 * PI) / (2 * b) * j * (inverse ? 1 : -1));
            for (int k = 0; k < n; k += b * 2) {
                // k を先頭とするブロック
                complex<double> s = a[j + k];         // 前
                complex<double> t = a[j + k + b] * w; // 後
                a[j + k] = s + t;                     // 前の更新
                a[j + k + b] = s - t;                 // 後の更新
            }
        }
    }
    // 逆変換時にサイズで割る調整
    if (inverse)
        for (int i = 0; i < n; i++)
            a[i] /= n;
    return a;
}
// Cooley–Tukey FFT algorithm O(N log N)
vector<complex<double>> fft(vector<double> a, bool inverse = false) {
    vector<complex<double>> a_complex(a.size());
    for (int i = 0; i < a.size(); i++)
        a_complex[i] = complex<double>(a[i], 0);
    return fft(a_complex, inverse);
}
// FFT による畳み込み O(N log N)
vector<double> convolve(vector<double> a, vector<double> b) {
    int s = a.size() + b.size() - 1; // 畳み込み結果のサイズ
    int t = 1;                       // FFT に使う配列のサイズ（2 の累乗）
    while (t < s)
        t *= 2;
    a.resize(t); // FFT するためにリサイズ
    b.resize(t); // FFT するためにリサイズ
    vector<complex<double>> A = fft(a);
    vector<complex<double>> B = fft(b);
    for (int i = 0; i < t; i++) {
        A[i] *= B[i]; // 畳み込み結果の FFT 結果を得る
    }
    A = fft(A, true); // IFFT で畳み込み結果を得る
    a.resize(s);      // 畳み込み結果を入れるためにリサイズ
    for (int i = 0; i < s; i++)
        a[i] = A[i].real(); // 実部が答え
    return a;
}



// FFT 
// https://atcoder.jp/contests/abc149/submissions/9295594
// こっちのほうが早くて ll にも対応しているから誤差の心配がなさそう
namespace FFT {
    const int N = 20;
    const int MAXN = (1 << N);
    const double PI = acos(-1.0);
 
    class cmplx {
    private:
        double x, y;
    public:
        cmplx() : x(0.0), y(0.0) {}
 
        cmplx(double a) : x(a), y(0.0) {}
 
        cmplx(double a, double b) : x(a), y(b) {}
 
        double get_real() { return this->x; }
 
        double get_img() { return this->y; }
 
        cmplx conj() { return cmplx(this->x, -(this->y)); }
 
        cmplx operator=(const cmplx &a) {
            this->x = a.x;
            this->y = a.y;
            return *this;
        }
 
        cmplx operator+(const cmplx &b) { return cmplx(this->x + b.x, this->y + b.y); }
 
        cmplx operator-(const cmplx &b) { return cmplx(this->x - b.x, this->y - b.y); }
 
        cmplx operator*(const double &num) { return cmplx(this->x * num, this->y * num); }
 
        cmplx operator/(const double &num) { return cmplx(this->x / num, this->y / num); }
 
        cmplx operator*(const cmplx &b) {
            return cmplx(this->x * b.x - this->y * b.y, this->y * b.x + this->x * b.y);
        }
 
        cmplx operator/(const cmplx &b) {
            cmplx temp(b.x, -b.y);
            cmplx n = (*this) * temp;
            return n / (b.x * b.x + b.y * b.y);
        }
    };
 
    cmplx w[MAXN];
    cmplx f1[MAXN];
    int rev[MAXN];
 
    void ReserveBits(int k) {
        static int rk = -1, lim;
        if (k == rk) return;
        rk = k, lim = 1 << k;
        for (int i = 1; i <= lim; ++i) {
            int j = rev[i - 1], t = k - 1;
            while (t >= 0 && ((j >> t) & 1)) {
                j ^= 1 << t;
                --t;
            }
            if (t >= 0) {
                j ^= 1 << t;
                --t;
            }
            rev[i] = j;
        }
    }
 
    void fft(cmplx *a, int k) {
        ReserveBits(k);
        int n = 1 << k;
        for (int i = 0; i < n; ++i)
            if (rev[i] > i) swap(a[i], a[rev[i]]);
        for (int l = 2, m = 1; l <= n; l += l, m += m) {
            if (w[m].get_real() == 0 && w[m].get_img() == 0) {
                double angle = PI / m;
                cmplx ww(cos(angle), sin(angle));
                if (m > 1) {
                    for (int j = 0; j < m; ++j) {
                        if (j & 1) w[m + j] = w[(m + j) / 2] * ww;
                        else w[m + j] = w[(m + j) / 2];
                    }
                } else w[m] = cmplx(1, 0);
            }
            for (int i = 0; i < n; i += l) {
                for (int j = 0; j < m; ++j) {
                    cmplx v = a[i + j], u = a[i + j + m] * w[m + j];
                    a[i + j] = v + u;
                    a[i + j + m] = v - u;
                }
            }
        }
    }
 
    vector<long long> multiply(const vector<long long> &a, const vector<long long> &b) {
        int k = 1;
        while ((1 << k) < (a.size() + b.size())) ++k;
        int n = (1 << k);
        for (int i = 0; i < n; ++i) f1[i] = cmplx(0, 0);
        for (int i = 0; i < a.size(); ++i) f1[i] = f1[i] + cmplx(a[i], 0);
        for (int i = 0; i < b.size(); ++i) f1[i] = f1[i] + cmplx(0, b[i]);
        fft(f1, k);
        for (int i = 0; i <= n / 2; ++i) {
            cmplx p = f1[i] + f1[(n - i) % n].conj();
            cmplx _q = f1[(n - i) % n] - f1[i].conj();
            cmplx q(_q.get_img(), _q.get_real());
            f1[i] = (p * q) * 0.25;
            if (i > 0) f1[(n - i)] = f1[i].conj();
        }
        for (int i = 0; i < n; ++i) f1[i] = f1[i].conj();
        fft(f1, k);
        vector<long long> ans(a.size() + b.size() - 1);
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = (long long) (f1[i].get_real() / n + 0.5);
        }
        return ans;
    }
};
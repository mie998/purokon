// typedef
typedef pair<int, int> P;
typedef tuple<int, int, int> P3;
typedef vector<vector int> Graph;
// sort by P.first (asd)
bool comPair(const P &firstElof, const P &secondElof) {
    return firstElof.first < secondElof.first;
}
bool compairTuple1(const P3 &firstElof, const P3 &secondElof) {
    return get<0>(firstElof) < get<0>(secondElof);
}

// moving 4-direction
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {1, 0, -1, 1, 0, -1, 1, -1};

long long modpow(long long m, long long p) {
    if (p == 0) return 1;
    if (p % 2)
        return m * modpow(m, p - 1) % MOD;
    else {
        long res = modpow(m, p / 2);
        return res * res % MOD;
    }
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// momory_safe
long calcComb(int a, int b) {
    if (b > a - b) return calcComb(a, a - b);
    long mul = 1;
    long div = 1;
    for (int i = 0; i < b; i++) {
        mul *= (a - i);
        div *= (i + 1);
        mul %= MOD;
        div %= MOD;
    }
    long res = mul * modpow(div, MOD - 2) % MOD;
    return res;
}

long long fac[MAX_N], finv[MAX_N], inv[MAX_N];
// テーブルを作る前処理 from: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// factorial
long long fact(int n) {
    if (n == 1) return fac[n] = 1;
    if (fac[n]) return fac[n];
    return fac[n] = (fact(n - 1) * n) % MOD;
}

// how to use priority_queue on pair
auto comPair = [](const P &firstElof, const P &secondElof) {
    if (firstElof.second != secondElof.second)
        return firstElof.second < secondElof.second;
    else
        return firstElof.first > secondElof.first;
};
priority_queue<P, vector<P>, decltype(comPair)> que(comPair);

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long extgcd(long long a, long long b, long long &x, long long &y) {
    long long d = a;
    if (d != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int string_to_int(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += (s[i] - '0') * pow(10, s.size() - 1 - i);
    }
    return ans;
}

int char_to_int(char c) {
    return c - '0';
}

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}

// コンテナ出力効率化
template <class Type>
void line(const Type &a) {
    int cnt = 0;
    for (const auto &elem : a) {
        if (cnt++) cout << ' ';
        cout << elem;
    }
    cout << '\n';
}

// import from https://rsk0315.github.io/library/library/utility/make/vector.cpp.html
// for c++14
namespace detail {
template <typename Tp, size_t N>
std::vector<Tp> make_vector(
    std::vector<size_t> &sizes,
    typename std::enable_if<(N == 1), Tp const &>::type x) {
    return std::vector<Tp>(sizes[0], x);
}
template <typename Tp, size_t N>
auto make_vector(
    std::vector<size_t> &sizes,
    typename std::enable_if<(N > 1), Tp const &>::type x) {
    size_t size = sizes[N - 1];
    sizes.pop_back();
    return std::vector<decltype(make_vector<Tp, N - 1>(sizes, x))>(
        size, make_vector<Tp, N - 1>(sizes, x));
}
} // namespace detail

template <typename Tp, size_t N>
auto make_vector(size_t const (&sizes)[N], Tp const &x = Tp()) {
    std::vector<size_t> s(N);
    for (size_t i = 0; i < N; ++i)
        s[i] = sizes[N - i - 1];
    return detail::make_vector<Tp, N>(s, x);
}

// for c++17
namespace detail {
template <typename Tp, size_t Nb>
auto make_vector(std::vector<size_t> &sizes, Tp const &x) {
    if constexpr (Nb == 1) {
        return std::vector(sizes[0], x);
    } else {
        size_t size = sizes[Nb - 1];
        sizes.pop_back();
        return std::vector(size, make_vector<Tp, Nb - 1>(sizes, x));
    }
}
} // namespace detail

template <typename Tp, size_t Nb>
auto make_vector(size_t const (&sizes)[Nb], Tp const &x = Tp()) {
    std::vector<size_t> s(Nb);
    for (size_t i = 0; i < Nb; ++i)
        s[i] = sizes[Nb - i - 1];
    return detail::make_vector<Tp, Nb>(s, x);
}

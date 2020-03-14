#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define for_each(e, v) for (auto &e : v)
#define all(x) (x).begin(), (x).end()
#define CYES cout << "Yes" << endl
#define CNO cout << "No" << endl
#define SPC(x) cout << fixed << setprecision(x)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = __INT_MAX__;               // 2^31 - 1
const long long INFLL = __LONG_LONG_MAX__; // 2^61 - 1
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
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

long long modpow(long long m, long long p) {
    if (p == 0) return 1;
    if (p % 2)
        return m * modpow(m, p - 1) % MOD;
    else {
        long res = modpow(m, p / 2);
        return res * res % MOD;
    }
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
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

struct mint {
    // Preparation: MOD is already defined.
    ll value;

    mint(ll value = 0) : value((value % MOD + MOD) % MOD) {}

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    mint pow(mint m) const {
        return pow(m.value);
    }

    mint inv() const {
        ll a = value, b = MOD, u = 1, v = 0;
        while (b) {
            ll t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        u %= MOD;
        return u;
    }

    mint &operator+=(const mint a) {
        if ((value += a.value) >= MOD) value -= MOD;
        return *this;
    }
    mint &operator-=(const mint a) {
        if ((value += MOD - a.value) >= MOD) value -= MOD;
        return *this;
    }
    mint &operator*=(const mint a) {
        (value *= a.value) %= MOD;
        return *this;
    }
    mint &operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Hello World" << endl;
    } else {
        int a, b;
        cin >> a >> b;
        out(a + b);
    }
    return 0;
}

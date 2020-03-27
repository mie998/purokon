#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define revrepeat(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define foreach(e, v) for (auto &e : v)
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
constexpr int MOD = 1e9 + 7;
constexpr int INF = __INT_MAX__;               // 2^31 - 1
constexpr long long INFLL = __LONG_LONG_MAX__; // 2^61 - 1
constexpr int MAX_N = 1e5 * 2 + 5;
constexpr double PI = acos(-1);

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

int main() {
    COMinit();
    int n;
    cin >> n;
    vi a(n);
    map<int, int> dict;
    rep(i, n) cin >> a[i];
    rep(i, n) dict[a[i]]++;

    ll sum = 0;
    foreach (me, dict) {
        auto e = me.second;
        if (e > 1)
            sum += COM(e, 2);
    }
    rep(i, n) {
        if (dict[a[i]] > 1)
            out(sum - (dict[a[i]] - 1));
        else
            out(sum);
    }
}

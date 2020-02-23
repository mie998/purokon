#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (ll i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
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
typedef complex<ld> Point;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e9 + 5;
const double PI = acos(-1);

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

long long finv[200005], inv[200005];
ll n;
// テーブルを作る前処理 from: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
void COMinit() {
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i <= 200000; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(int k) {
    mint fac(1);
    for (ll i = n - k + 1; i < n + 1; i++) {
        fac *= i;
    }
    return fac.value * (finv[k] % MOD) % MOD;
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

int main() {
    ll a, b;
    cin >> n >> a >> b;
    // debug("dfs");
    COMinit();
    mint ans(0);
    ans += modpow(2, n) - 1;
    mint nCa(COM(a)), nCb(COM(b));
    // debug(nCa.value);
    // debug(nCb.value);
    ans -= nCa + nCb;
    out(ans.value);
    return 0;
}

d

#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<ld> Point;
typedef vector<vector<int>> Graph;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
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

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

// factorization O(sqrt(n))
map<int, int> prime_factor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> all_lcm;
    vector<map<int, int>> factorizations(n);
    rep(i, n) factorizations[i] = prime_factor(a[i]);
    for (auto p : factorizations) {
        for (auto m : p) {
            all_lcm[m.first] = max(m.second, all_lcm[m.first]);
        }
    }

    mint ans(0);
    rep(i, n) {
        map<int, int> cp_all_lcm = all_lcm;
        mint cnt(1);
        for (auto p : factorizations[i]) {
            cp_all_lcm[p.first] -= p.second;
            // debug(p.first);
            // debug(p.second);
        }
        for (auto p : all_lcm) {
            cnt.value *= pow(p.first, cp_all_lcm[p.first]);
            // debug(i);
            // debug(p.first);
            // debug(cp_all_lcm[p.first]);
            // debug(cnt.value);
        }
        ans += cnt.value;
    }
    out(ans.value);
}

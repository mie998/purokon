#include <bits/stdc++.h>
using namespace std;

//def
#define debug(x) cout << #x << ": " << x << '\n'
#define out(x) cout << x << '\n'
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
constexpr ll MOD = 1e18;
constexpr int INF = __INT_MAX__;                    // 2^31 - 1
constexpr long long INFLL = __LONG_LONG_MAX__ / 10; // 2^61 - 1
constexpr int MAX_N = 1e5 + 5;
constexpr double PI = acos(-1);

long long modpow(long long m, long long p) {
    if (p < 0) return 0;
    if (p == 0) return 1;
    if (p > 50) return INFLL / 3;
    if (p % 2)
        return m * modpow(m, p - 1);
    else {
        long res = modpow(m, p / 2);
        return res * res;
    }
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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vi a(n + 1);
    rep(i, n + 1) cin >> a[i];

    vl bound(n + 1);
    ll b = 1;
    bound[0] = 1;
    repeat(i, 1, n + 1) {
        b = min(b * 2, INFLL);
        bound[i] = b;
        b -= a[i];
    }

    ll sum = 0;
    ll child = 0;
    bool ok = true;
    revrepeat(i, 1, n + 1) {
        if (a[i] + (child + 1) / 2 > bound[i]) ok = false;
        child += a[i];
        child = min(child, bound[i]);
        sum += child;
    }
    if (n != 0 and a[0] != 0) ok = false;
    if (n == 0 and a[0] != 1) ok = false;
    if (ok) {
        if (n == 0)
            out(1);
        else
            out(sum + 1);
    } else
        out(-1);
    return 0;
}

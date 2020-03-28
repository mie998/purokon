#include <bits/stdc++.h>
using namespace std;

//def
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
constexpr int MAX_N = 1e5 + 5;
constexpr double PI = acos(-1);

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
    ll k, n;
    cin >> k >> n;
    vl a(n);
    rep(i, n) cin >> a[i];

    ll l, r;
    ll ans = INF;
    rep(i, n) {
        if (i - 1 < 0)
            l = a[n - 1];
        else
            l = a[i - 1];
        if (i == n - 1)
            r = a[0];
        else
            r = a[i + 1];

        ll l_dist = abs(l - a[i]);
        ll r_dist = abs(r - a[i]);
        chmin(l_dist, k - l_dist);
        chmin(r_dist, k - r_dist);
        ll dist = min(k - l_dist, k - r_dist);
        // debug(l_dist);
        // debug(r_dist);
        // debug(dist);
        chmin(ans, dist);
    }
    out(ans);
    return 0;
}

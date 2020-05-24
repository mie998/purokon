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

ll n, a, b, c, d;
map<ll, ll> memo;
ll dp(ll n) {
    if (n == 0) return 0;
    if (n == 1) return d;
    if (memo.count(n)) return memo[n];

    ll l2 = (n / 2) * 2;
    ll l3 = (n / 3) * 3;
    ll l5 = (n / 5) * 5;
    ll r2 = ((n + 1) / 2) * 2;
    ll r3 = ((n + 2) / 3) * 3;
    ll r5 = ((n + 4) / 5) * 5;

    ll res = 1e18;
    if (n < res / d) res = n * d;
    chmin(res, abs(l2 - n) * d + a + dp(l2 / 2));
    chmin(res, abs(r2 - n) * d + a + dp(r2 / 2));
    chmin(res, abs(l3 - n) * d + b + dp(l3 / 3));
    chmin(res, abs(r3 - n) * d + b + dp(r3 / 3));
    chmin(res, abs(l5 - n) * d + c + dp(l5 / 5));
    chmin(res, abs(r5 - n) * d + c + dp(r5 / 5));

    return memo[n] = res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(i, t) {
        memo.clear();
        cin >> n >> a >> b >> c >> d;
        cout << dp(n) << endl;
    }
    return 0;
}

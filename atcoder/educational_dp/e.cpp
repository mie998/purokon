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
#define CYES cout << "Yes" << endl
#define CNO cout << "No" << endl
#define SPC(x) cout << fixed << setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
typedef pair<int, int> P;
typedef complex<ld> Point;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

ll dp[105][100500];
ll weight[105];
ll value[105];

int main() {
    ll n, w;
    ll v = MAX_V;
    cin >> n >> w;
    rep(i, n) {
        cin >> weight[i] >> value[i];
    }

    rep(i, n) {
        rep(j, v) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    rep(i, n) {
        rep(x, v) {
            if (x - value[i] >= 0)
                dp[i + 1][x] = min(dp[i][x], dp[i][x - value[i]] + weight[i]);
            else
                dp[i + 1][x] = min(dp[i + 1][x], dp[i][x]);

            // debug(i);
            // debug(x);
            // debug(dp[i][x]);
        }
    }

    ll ans = 0;
    rep(i, v) {
        if (dp[n][i] <= w)
            ans = i;
    }

    out(ans);
    return 0;
}

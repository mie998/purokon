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
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

ll dp[105][100005];
int weight[105];
int value[105];

int main() {
    int n, w;
    cin >> n >> w;
    rep(i, n) {
        cin >> weight[i] >> value[i];
    }
    repeat(i, 1, w + 1) {
        dp[0][i] = -INF;
    }

    rep(i, n) {
        rep(x, w + 1) {
            if (x - weight[i] >= 0)
                dp[i + 1][x] = max(dp[i][x], dp[i][x - weight[i]] + value[i]);
            else
                dp[i + 1][x] = dp[i][x];

            debug(i);
            debug(x);
            debug(dp[i][x]);
        }
    }

    ll res = -INF;
    rep(i, w) {
        res = max(res, dp[n][i]);
    }
    out(dp[n][w]);
    return 0;
}

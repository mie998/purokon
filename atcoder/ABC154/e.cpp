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

ll get_num(string s, int m) {
    int l = s.size();
    ll dp[105][2][5]; // digit, smaller, not_zero_num
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    rep(i, l) {
        rep(j, 2) {
            rep(k, m + 1) {
                int d = s[i] - '0';
                rep(x, (j ? 9 : d) + 1) {
                    dp[i + 1][j || (x < d)][min(m + 1, (x == 0) ? k : k + 1)] += dp[i][j][k];
                }
                // debug(i);
                // debug(j);
                // debug(k);
                // debug(dp[i][j][k]);
            }
        }
    }

    return dp[l][0][m] + dp[l][1][m];
}

int main() {
    string s;
    int m;
    cin >> s >> m;
    out(get_num(s, m));
}

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

// LCS + restore_path
// https://qiita.com/nomikura/items/f30686df3df0ddb4d338
int dp[3005][3005];
int pre[3005][3005]; // 1: i,j から 2: i+1,j から 3: i,j+1 から
string lcs_restore(string &x, string &y) {
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    int xn = x.size();
    int yn = y.size();
    for (int i = 0; i < xn; i++) {
        for (int j = 0; j < yn; j++) {
            if (x[i] == y[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                pre[i + 1][j + 1] = 1;
            } else {
                if (max(dp[i][j + 1], dp[i + 1][j]) == dp[i + 1][j]) {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                    pre[i + 1][j + 1] = 2;
                } else {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                    pre[i + 1][j + 1] = 3;
                }
            }
        }
    }
    string ans = "";
    while (pre[xn][yn] != 0) {
        if (pre[xn][yn] == 1) {
            xn -= 1, yn -= 1;
            ans += x[xn];
        } else if (pre[xn][yn] == 2) {
            yn -= 1;
        } else {
            xn -= 1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    string ans = lcs_restore(s, t);
    cout << ans << endl;
    return 0;
}

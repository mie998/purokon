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
typedef complex<ld> Point;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

ll dp[1000000][2]; // digit, look_forward_flag(0: exact, 1: look_forward)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    reverse(all(s));
    dp[0][0] = 0;
    dp[0][1] = INF;
    rep(i, n) {
        int c = s[i] - '0';
        if (i == n - 1) {
            dp[i + 1][0] = min(dp[i][0] + c, dp[i][1] + c + 1);
            dp[i + 1][1] = min(dp[i][0] + (11 - c), dp[i][1] + (10 - c));
        } else {
            dp[i + 1][0] = min(dp[i][0] + c, dp[i][1] + c + 1);
            dp[i + 1][1] = min(dp[i][0] + (10 - c), dp[i][1] + (10 - (c + 1)));
        }
        // debug(i);
        // debug(dp[i + 1][0]);
        // debug(dp[i + 1][1]);
    }
    out(min(dp[n][0], dp[n][1]));
    return 0;
}

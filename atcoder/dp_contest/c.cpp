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

int dp[MAX_N][3];
int a[MAX_N][3];

int main() {
    int n;
    cin >> n;
    repeat(i, 1, n + 1) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    repeat(i, 1, n + 1) {
        rep(j, 3) {
            rep(k, 3) {
                if (j == k)
                    continue;
                dp[i][k] = max(dp[i][k], dp[i - 1][j] + a[i][k]);
            }
        }
    }

    out(max(dp[n][0], max(dp[n][1], dp[n][2])));
    return 0;
}

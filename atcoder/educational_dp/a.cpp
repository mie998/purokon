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

int dp[MAX_N];
int h[MAX_N];

int rec(int n) {
    if (n == 0)
        return 0;

    if (dp[n] == INF) {
        int res = INF;
        if (n - 1 >= 0) res = min(res, rec(n - 1) + abs(h[n] - h[n - 1]));
        if (n - 2 >= 0) res = min(res, rec(n - 2) + abs(h[n] - h[n - 2]));
        dp[n] = res;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    rep(i, n) {
        dp[i] = INF;
        cin >> h[i];
    }

    dp[0] = 0;

    // rep(i, n) {
    //     if (i + 1 < n) dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    //     if (i + 2 < n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));

    //     // debug(i);
    //     // debug(dp[i]);
    // }

    rec(n - 1);
    out(dp[n - 1]);
    return 0;
}

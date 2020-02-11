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
typedef vector<vector<int>> Graph;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1L);

vi operation;
vi dp;

int rec(int n) {
    if (n == 0)
        return 0;

    if (dp[n] == INF) {
        int res = INF;
        for (auto op : operation) {
            if (n - op >= 0) {
                res = min(res, rec(n - op) + 1);
            }
        }
        dp[n] = res;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    operation.push_back(1);
    for (int i = 6; i <= n; i *= 6) {
        operation.push_back(i);
    }
    for (int i = 9; i <= n; i *= 9) {
        operation.push_back(i);
    }

    dp = vi(n + 1, INF);
    rec(n);
    out(dp[n]);
}

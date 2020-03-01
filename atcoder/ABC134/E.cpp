#include <bits/stdc++.h>
using namespace std;
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
const int INF = 1e9 + 7;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);
// LIS(longest increasing subsequence)
// http://even-eko.hatenablog.com/entry/2013/09/05/215236
int dp[100005];
int lis(vector<ll> &a) {
    int n = a.size();
    fill(dp, dp + n, INF);
    for (int i = 0; i < n; ++i) {
        *upper_bound(dp, dp + n, a[i]) = a[i];
    }
    return lower_bound(dp, dp + n, INF) - dp;
}

int main() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    reverse(all(a));
    int ans = lis(a);
    out(ans);
}

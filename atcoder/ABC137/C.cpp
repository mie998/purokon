#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 100 + 5;
const int MAX_N = 1e7 + 5;

long long dp[MAX_N][3];
long long nCr(int n, int r) {
    if (n == r) return dp[n][r] = 1;
    if (r == 0) return dp[n][r] = 1;
    if (r == 1) return dp[n][r] = n;
    if (dp[n][r]) return dp[n][r];
    return dp[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % M;
}

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    ll ans = 0;
    rep(i, n) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ans += mp[s];
        mp[s]++;
    }
    cout << ans << endl;
}

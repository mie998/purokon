// LCS(longest common subsequence)
// http://www.deqnotes.net/acmicpc/1458/
int dp[1005][1005];
int lcs(string &x, string &y) {
    memset(dp, 0, sizeof(dp));
    int xn = x.size();
    int yn = y.size();
    for (int i = 0, i < xn; i++) {
        for (int j = 0, j < yn; j++) {
            if (x[i] == y[j])
                dp[i + 1][j + 1] = max(dp[i][j] + 1, max(dp[i][j + 1], dp[i + 1][j]));
            else
                dp[i + 1][j + 1] = max(dp[i][j], max(dp[i][j + 1], dp[i + 1][j]));
        }
    }
    return dp[xn][yn];
}

// LIS(longest increasing subsequence)
// http://even-eko.hatenablog.com/entry/2013/09/05/215236
int dp[100005];
int lis(vector<int> &a) {
    int n = a.size();
    fill(dp, dp + n, INF);
    for (int i = 0; i < n; ++i) {
        *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    return lower_bound(dp, dp + n, INF) - dp;
}

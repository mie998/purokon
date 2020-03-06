// LCS(longest common subsequence)
// http://www.deqnotes.net/acmicpc/1458/
int dp[3005][3005];
int lcs(string &x, string &y) {
    memset(dp, 0, sizeof(dp));
    int xn = x.size();
    int yn = y.size();
    for (int i = 0; i < xn; i++) {
        for (int j = 0; j < yn; j++) {
            if (x[i] == y[j])
                dp[i + 1][j + 1] = max({dp[i][j] + 1, dp[i][j + 1], dp[i + 1][j]});
            else
                dp[i + 1][j + 1] = max({dp[i][j], dp[i][j + 1], dp[i + 1][j]});
        }
    }
    return dp[xn][yn];
}

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
            ans += s[xn];
        } else if (pre[xn][yn] == 2) {
            yn -= 1;
        } else {
            xn -= 1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

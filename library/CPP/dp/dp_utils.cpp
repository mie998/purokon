template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
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

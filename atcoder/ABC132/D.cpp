#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9;

long long dp[2000][2000];
ll fac[2000];

long long nCr(int n, int r) {
    if (n == r) return dp[n][r] = 1;
    if (r == 0) return dp[n][r] = 1;
    if (r == 1) return dp[n][r] = n;
    if (dp[n][r]) return dp[n][r];
    return dp[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % M;
}

ll fact(int n) {
    if (n == 1) return fac[n] = 1;
    if (fac[n]) return fac[n];
    return fac[n] = fact(n - 1) * n;
}

int main() {
    int n, k;
    int i;
    cin >> n >> k;
    int blue = k;
    int red = n - k;
    for (i = 1; i <= k; i++) {
        cout << (nCr(red + 1, i) * fact(max(1, min(i, blue - i)))) % M << endl;
    }
}

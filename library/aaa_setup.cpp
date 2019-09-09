// common include
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
const int M = 1e9 + 7;
const int INF = 1e9;

// typedef
typedef pair<int, int> P;
typedef tuple<int, int, int> P3;
// sort by P.first (asd)
bool comPair(const P &firstElof, const P &secondElof) {
    return firstElof.first < secondElof.first;
}
bool compairTuple1(const P3 &firstElof, const P3 &secondElof) {
    return get<0>(firstElof) < get<0>(secondElof);
}

// moving 4-direction
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// Combination
long long dp[MAX][MAX];

long long nCr(int n, int r) {
    if (n == r) return dp[n][r] = 1;
    if (r == 0) return dp[n][r] = 1;
    if (r == 1) return dp[n][r] = n;
    if (dp[n][r]) return dp[n][r];
    return dp[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % M;
}

// save memory
int MOD = 1e9 + 7;
long modpow(long m, long p) {
    if (p == 0) return 1;
    if (p % 2)
        return m * modpow(m, p - 1) % MOD;
    else {
        long res = modpow(m, p / 2);
        return res * res % MOD;
    }
}
long calcComb(int a, int b) {
    if (b > a - b) return calcComb(a, a - b);
    long mul = 1;
    long div = 1;
    for (int i = 0; i < b; i++) {
        mul *= (a - i);
        div *= (i + 1);
        mul %= MOD;
        div %= MOD;
    }
    long res = mul * modpow(div, MOD - 2) % MOD;
    return res;
}

long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理 from: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// factorial
long long fac[MAX];

long long fact(int n) {
    if (n == 1) return fac[n] = 1;
    if (fac[n]) return fac[n];
    return fac[n] = (fact(n - 1) * n) % MOD;
}

// adjecent-list
struct Edge {
    int to;
    int weight;
};
const int MAX = 1e5 + 5;
vector<Edge> Graph[MAX];
bool checked[MAX];
int color[MAX];

// how to use priority_queue on pair
auto comPair = [](const P &firstElof, const P &secondElof) {
    if (firstElof.second != secondElof.second)
        return firstElof.second < secondElof.second;
    else
        return firstElof.first > secondElof.first;
};
priority_queue<P, vector<P>, decltype(comPair)> que(comPair);

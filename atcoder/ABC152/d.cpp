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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<ld> Point;
typedef vector<vector<int>> Graph;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

long long fac[MAX_N], finv[MAX_N], inv[MAX_N];
// テーブルを作る前処理 from: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX_N; i++) {
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
long long fact(int n) {
    if (n == 1) return fac[n] = 1;
    if (fac[n]) return fac[n];
    return fac[n] = (fact(n - 1) * n) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int> zxz(10, 0);
    vector<int> mxn(100, 0);
    COMinit();
    repeat(i, 1, n + 1) {
        string s = to_string(i);
        int a = (s[0] - '0');
        int b = (s.back() - '0');
        if (s[0] == s.back()) {
            zxz[a]++;
        } else if (i % 10 != 0) {
            int idx = 10 * a + b;
            mxn[idx]++;
        }
    }
    ll ans = 0;
    repeat(i, 1, 10) {
        // debug(i);
        // debug(zxz[i]);
        ans += zxz[i] + COM(zxz[i], 2) * 2;
    }
    repeat(i, 10, 100) {
        string s = to_string(i);
        // debug(i);
        // debug(mxn[i]);
        if (i % 10 == 0)
            continue;
        else {
            int a = (s[0] - '0');
            int b = (s.back() - '0');
            int idx_1 = a * 10 + b;
            int idx_2 = b * 10 + a;
            ans += mxn[idx_1] * mxn[idx_2];
        }
    }
    out(ans);
    return 0;
}

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
typedef pair<int, int> P;
typedef vector<vector<int>> Graph;
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 100000 + 5;
const int MAX_N = 1e6 + 5;
const double PI = acos(-1);

// Combination

// save memory
int mod = 1e9 + 7;
int MOD = 1e9 + 7;
long modpow(long m, long p) {
    if (p == 0) return 1;
    if (p % 2)
        return m * modpow(m, p - 1) % mod;
    else {
        long res = modpow(m, p / 2);
        return res * res % mod;
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

int main() {
    int x, y;
    cin >> x >> y;
    if ((2 * x - y) % 3 != 0 || (2 * y - x) % 3 != 0 || (x + y) % 3 != 0 || (2 * x - y) < 0 || (2 * y - x) < 0) {
        out(0);
    } else {
        int a = (2 * x - y) / 3;
        int b = (2 * y - x) / 3;
        long ans = calcComb(a + b, max(a, b));
        out(ans);
    }
}

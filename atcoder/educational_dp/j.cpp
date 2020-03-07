#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define for_each(e, v) for (auto &e : v)
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
const int MOD = 1e9 + 7;
const int INF = __INT_MAX__;               // 2^31 - 1
const long long INFLL = __LONG_LONG_MAX__; // 2^61 - 1
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

double dp[305][305][305];
int n;

double f(int c1, int c2, int c3) {
    int sum = c1 + c2 + c3;
    if (dp[c1][c2][c3] || sum == 0) return dp[c1][c2][c3];

    dp[c1][c2][c3] += 1.0 * n / sum;
    if (c1 > 0) dp[c1][c2][c3] += f(c1 - 1, c2, c3) * c1 / sum;
    if (c2 > 0) dp[c1][c2][c3] += f(c1 + 1, c2 - 1, c3) * c2 / sum;
    if (c3 > 0) dp[c1][c2][c3] += f(c1, c2 + 1, c3 - 1) * c3 / sum;

    return dp[c1][c2][c3];
}

int main() {
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int cnt_1, cnt_2, cnt_3;
    cnt_1 = cnt_2 = cnt_3 = 0;
    SPC(10);
    rep(i, n) {
        if (a[i] == 1) cnt_1++;
        if (a[i] == 2) cnt_2++;
        if (a[i] == 3) cnt_3++;
    }

    out(f(cnt_1, cnt_2, cnt_3));
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

//def
#define debug(x) cout << #x << ": " << x << '\n'
#define out(x) cout << x << '\n'
#define repeat(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define revrepeat(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define foreach(e, v) for (auto &e : v)
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
constexpr int MOD = 1e9 + 7;
constexpr int INF = __INT_MAX__;               // 2^31 - 1
constexpr long long INFLL = __LONG_LONG_MAX__; // 2^61 - 1
constexpr int MAX_N = 1e5 + 5;
constexpr double PI = acos(-1);

ll dp[3050][3050][5];
ll value[3050][3050];
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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll r, c, k;
    cin >> r >> c >> k;
    vl col(k), row(k), v(k);
    rep(i, k) cin >> col[i] >> row[i] >> v[i];
    rep(i, k) col[i]--, row[i]--;
    rep(i, k) value[col[i]][row[i]] += v[i];

    if (value[0][0] > 0) dp[0][0][1] += value[0][0];
    rep(x, r) rep(y, c) rep(z, 4) {
        if (z == 3) {
            chmax(dp[x][y + 1][z], dp[x][y][z]);
            chmax(dp[x + 1][y][1], dp[x][y][z] + value[x + 1][y]); //行移動、つかう
            chmax(dp[x + 1][y][0], dp[x][y][z]);
        } else {
            chmax(dp[x][y + 1][z + 1], dp[x][y][z] + value[x][y + 1]); //列移動、つかう
            chmax(dp[x][y + 1][z], dp[x][y][z]);
            chmax(dp[x + 1][y][1], dp[x][y][z] + value[x + 1][y]); //行移動、つかう
            chmax(dp[x + 1][y][0], dp[x][y][z]);
        }
    }
    // debug(dp[0][3][0]);
    // debug(dp[0][3][1]);
    // debug(dp[0][3][2]);
    // debug(dp[0][3][3]);
    r--, c--;
    out(max({dp[r][c][3], dp[r][c][2], dp[r][c][1], dp[r][c][0]}));

    return 0;
}

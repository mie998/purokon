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
typedef complex<ld> Point;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

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

int dp[1005][(1 << 12) + 5];

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    fill(dp[0], dp[1005], INF);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        int temp;
        int mask = 0;
        rep(j, b) {
            cin >> temp;
            mask += 1 << (temp - 1);
        }
        // debug(mask);
        v.emplace_back(a, mask);
    }

    dp[0][0] = 0;
    rep(i, m) {
        rep(j, 1 << n) {
            int mask = v[i].second;
            // debug(mask);
            // debug(j);
            chmin(dp[i + 1][j | mask], dp[i][j] + v[i].first);
            chmin(dp[i + 1][j], dp[i][j]);
            // debug(i);
            // debug(j);
            // debug(dp[i][j]);
            // debug(dp[3][3]);
        }
    }

    if (dp[m][(1 << n) - 1] == INF) {
        out(-1);
    } else {
        // debug((1 << n) - 1);
        out(dp[m][(1 << n) - 1]);
    }
    return 0;
}

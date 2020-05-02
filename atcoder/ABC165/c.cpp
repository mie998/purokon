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

vii v;
void dfs(vi &nums, int m, int n, int i) {
    if (i == n) {
        reverse(all(nums));
        v.push_back(nums);
        return;
    }

    int nx = -1;
    foreach (c, nums)
        chmax(nx, c);
    nx++;

    rep(j, nx + 1) {
        vi x = nums;
        x.push_back(j + 1);
        dfs(x, m, n, i + 1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;
    vii p(q, vi(4));
    rep(i, q) {
        vi t(4);
        rep(j, 4) cin >> t[j];
        t[0]--, t[1]--;
        p[i] = t;
    }

    vi e = {1};
    rep(i, m) {
        vi z = e;
        z[0] += i;
        dfs(z, m, n, 0);
    }

    int ans = 0;
    foreach (e, v) {
        int cnt = 0;
        rep(i, q) {
            if ((e[p[i][1]] - e[p[i][0]]) == p[i][2]) cnt += p[i][3];
        }
        ans = max(ans, cnt);
    }

    out(ans);

    return 0;
}

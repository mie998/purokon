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

bool seen[200005];
int a[200005];
int depth[200005];
int ans = INF;
ll k;

void dfs(int s, int d) {
    if (seen[s]) {
        int si = d - depth[s];
        k = (k - depth[s]) % si + depth[s];
        return;
    }

    if (d == k + 1) {
        ans = s + 1;
        return;
    }

    seen[s] = true;
    depth[s] = d;
    dfs(a[s], d + 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;

    dfs(0, 1);
    rep(i, n) if (k == depth[i]) {
        ans = a[i] + 1;
    }

    out(ans);
    return 0;
}

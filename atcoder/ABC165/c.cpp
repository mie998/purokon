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
void dfs(vi &x, int n, int m, int idx) {
    if (idx == n) {
        v.push_back(x);
        return;
    }

    int mx = x.back();

    repeat(j, mx, m + 1) {
        vi z = x;
        z.push_back(j);
        dfs(z, n, m, idx + 1);
    }
}

struct p {
    int a;
    int b;
    int c;
    int d;
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<p> query(q);
    rep(i, q) cin >> query[i].a >> query[i].b >> query[i].c >> query[i].d;

    rep(i, m) {
        vi x = {i + 1};
        dfs(x, n, m, 1);
    }

    ll ans = 0;
    foreach (e, v) {
        ll cnt = 0;
        rep(i, q) {
            auto pic = query[i];
            if (e[pic.b - 1] - e[pic.a - 1] == pic.c) cnt += pic.d;
        }
        chmax(ans, cnt);
    }

    out(ans);

    return 0;
}

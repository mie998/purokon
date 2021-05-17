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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vl p(n), c(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> c[i];
    rep(i, n) p[i]--;

    ll ans = -INF;
    rep(i, n) {
        ll cycle_sum = 0, cycle_volume = 0;
        int v = i;
        while (true) {
            v = p[v];
            cycle_sum += c[p[v]];
            cycle_volume++;
            if (v == i) break;
        }

        int div = k / cycle_volume;
        int mod = k % cycle_volume;
        ll score = 0;
        score += max(0LL, div * cycle_sum);

        ll div_sum = 0, div_sum_max = -INF;
        if (div * cycle_sum < 0) mod = cycle_volume;
        rep(j, mod) {
            v = p[v];
            div_sum += c[p[v]];
            chmax(div_sum_max, div_sum);
            if (j > k) break;
            if (v == i) break;
        }
        score += div_sum_max;

        chmax(ans, score);

        // debug(i);
        // debug(score);
    }

    out(ans);
    return 0;
}

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

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    vl va(a);
    vl vb(b);
    rep(i, a) cin >> va[i];
    rep(i, b) cin >> vb[i];

    vector<pair<ll, ll>> xy(n);
    vl c(n);
    rep(i, n) {
        ll x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        xy[i] = make_pair(x, y);
        c[i] = z;
    }

    ll ans = INF;
    rep(i, n) {
        ans = min(ans, va[xy[i].first] + vb[xy[i].second] - c[i]);
    }

    sort(all(va));
    sort(all(vb));
    if (ans > va[0] + vb[0])
        ans = va[0] + vb[0];

    out(ans);

    return 0;
}

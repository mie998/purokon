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

int main() {
    ll n, d, a;
    cin >> n >> d >> a;
    vector<pair<ll, ll>> v(n);
    vl reach(n, 0);
    vl damage(n, 0);
    vl diff(n, 0);
    ll ans = 0;
    rep(i, n) cin >> v[i].first >> v[i].second;
    auto comPair = [](const P &firstElof, const P &secondElof) {
        return firstElof.first < secondElof.first;
    };
    sort(all(v), comPair);
    // debug(v[2].first);

    int r = 0;
    rep(l, n) {
        if (l == r) r++;

        while (v[r].first - v[l].first <= 2 * d && r < n) {
            r++;
        }

        // debug(l);
        // debug(r);

        reach[l] = r - 1;
    }

    rep(i, n) {
        ll res = v[i].second - damage[i];
        ll bomb_num;
        if (res <= 0)
            bomb_num = 0;
        else
            bomb_num = (res + a - 1) / a;
        ll bomb = bomb_num * a;

        ans += bomb_num;
        damage[i] += bomb;
        if (i == n - 1) break;
        if (i > 0)
            diff[i - 1] += bomb;
        if (reach[i] < n - 1)
            diff[reach[i]] -= bomb;
        damage[i + 1] = damage[i] + diff[i];

        // debug(i);
        // debug(reach[i]);
        // debug(damage[i]);
        // debug(bomb_num);
    }

    out(ans);

    return 0;
}

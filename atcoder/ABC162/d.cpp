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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt_r, cnt_g, cnt_b;
    rep(i, n) {
        if (s[i] == 'R') cnt_r.push_back(i);
        if (s[i] == 'G') cnt_g.push_back(i);
        if (s[i] == 'B') cnt_b.push_back(i);
    }

    ll ans = cnt_r.size() * cnt_g.size() * cnt_b.size();

    rep(i, cnt_r.size()) {
        rep(j, cnt_g.size()) {
            int r = cnt_r[i];
            int g = cnt_g[j];
            int diff = max(r, g) - min(r, g);
            if (diff % 2 == 0) {
                if (find(all(cnt_b), diff / 2 + min(r, g)) != cnt_b.end()) ans--;
            }
            if (find(all(cnt_b), diff + max(r, g)) != cnt_b.end()) ans--;
            if (find(all(cnt_b), min(r, g) - diff) != cnt_b.end()) ans--;
        }
    }

    out(ans);

    return 0;
}

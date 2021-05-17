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

string pc = "pairwise coprime";
string sc = "setwise coprime";
string nc = "not coprime";

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    ll g = a[0];
    map<int, int> dict;
    rep(i, n) {
        g = gcd(g, a[i]);
        int num = a[i];
        for (int x = 2; x * x <= num; x++) {
            if (num % x == 0) {
                while (num % x == 0) {
                    num /= x;
                }
                ++dict[x];
            }
        }
        if (num != 1) ++dict[num];
    }
    auto is_pc = [&]() {
        rep(i, 1000005) {
            if (dict[i] >= 2) return false;
        }
        return true;
    };
    if (is_pc()) {
        out(pc);
    } else if (g == 1) {
        out(sc);
    } else
        out(nc);

    return 0;
}

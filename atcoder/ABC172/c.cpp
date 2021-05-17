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

    ll n, m, k;
    cin >> n >> m >> k;
    deque<ll> a, b;
    rep(i, n) {
        ll t;
        cin >> t;
        a.push_back(t);
    }
    rep(i, m) {
        ll t;
        cin >> t;
        b.push_back(t);
    }

    ll sum = 0;
    ll ans = -1;
    while (sum < k and !(a.empty() and b.empty())) {
        if (a.empty()) {
            sum += b.front();
            ans++;
            b.pop_front();
        } else if (b.empty()) {
            sum += a.front();
            ans++;
            a.pop_front();
        } else {
            if (a.front() > b.front()) {
                sum += b.front();
                ans++;
                b.pop_front();
            } else {
                sum += a.front();
                ans++;
                a.pop_front();
            }
        }
    }
    if (a.empty() and b.empty()) ans++;
    out(ans);
}

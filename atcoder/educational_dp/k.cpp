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

bool dp[100005];
int main() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    rep(i, k + 1) {
        rep(j, n) {
            if (i + a[j] <= k && !dp[i]) dp[i + a[j]] = true;
        }
    }
    dp[k] ? out("First") : out("Second");
    return 0;
}

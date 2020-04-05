#include <bits/stdc++.h>
using namespace std;

//def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
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

vector<ll> runrun_numbers;
void dfs(ll curr, ll tail) {
    if (curr > 3234566667) return;

    runrun_numbers.push_back(curr);
    if (tail == 0) {
        dfs(curr * 10 + tail, tail);
        dfs(curr * 10 + tail + 1, tail + 1);
    } else if (tail == 9) {
        dfs(curr * 10 + tail - 1, tail - 1);
        dfs(curr * 10 + tail, tail);
    } else {
        dfs(curr * 10 + tail - 1, tail - 1);
        dfs(curr * 10 + tail, tail);
        dfs(curr * 10 + tail + 1, tail + 1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll k;
    cin >> k;

    repeat(i, 1, 10) dfs(i, i);
    // debug(runrun_numbers.size());
    sort(all(runrun_numbers));
    out(runrun_numbers[k - 1]);
    return 0;
}

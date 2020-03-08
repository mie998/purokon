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

bool seen[200005];
int ans[200005];
int color[200005];
map<int, int> color_cnt;
void dfs(int n, int depth, vii &graph) {
    if (seen[n])
        return;

    seen[n] = true;
    color[n] = depth % 2;
    color_cnt[depth % 2]++;
    for (auto e : graph[n]) {
        dfs(e, depth + 1, graph);
    }
}

int main() {
    int n;
    cin >> n;
    vii graph(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, 0, graph);

    int num_0 = n / 3;

    vi mod_0_list;
    vi mod_1_list;
    vi mod_2_list;
    repeat(i, 1, n + 1) {
        if (i % 3 == 0) {
            mod_0_list.push_back(i);
        } else if (i % 3 == 1) {

            mod_1_list.push_back(i);
        } else {

            mod_2_list.push_back(i);
        }
    }
    auto iter_0_list = mod_0_list.begin();
    auto iter_1_list = mod_1_list.begin();
    auto iter_2_list = mod_2_list.begin();
    vector<vector<int>::iterator> iter_list = {iter_0_list, iter_1_list, iter_2_list};

    if (color_cnt[0] <= num_0) {
        rep(i, n) {
            if (color[i] == 0) {
                ans[i] = *iter_list[0];
                iter_list[0]++;
            }
        }
    } else if (color_cnt[1] <= num_0) {
        rep(i, n) {
            if (color[i] == 1) {
                ans[i] = *iter_list[0];
                iter_list[0]++;
            }
        }
    } else {
        rep(i, n) {
            if (color[i] == 0) {
                if (iter_list[1] == mod_1_list.end()) {
                    ans[i] = *iter_list[0];
                    iter_list[0]++;
                } else {
                    ans[i] = *iter_list[1];
                    iter_list[1]++;
                }
            }
            if (color[i] == 1) {
                if (iter_list[2] == mod_2_list.end()) {
                    ans[i] = *iter_list[0];
                    iter_list[0]++;
                } else {
                    ans[i] = *iter_list[2];
                    iter_list[2]++;
                }
            }
        }
    }

    // rep(i, n) cout << ans[i] << ' ';
    rep(i, n) {
        if (ans[i] == 0) {
            if (iter_list[0] != mod_0_list.end()) {
                ans[i] = *iter_list[0];
                iter_list[0]++;
                continue;
            }
            if (iter_list[1] != mod_1_list.end()) {
                ans[i] = *iter_list[1];
                iter_list[1]++;
                continue;
            }
            if (iter_list[2] != mod_2_list.end()) {
                ans[i] = *iter_list[2];
                iter_list[2]++;
                continue;
            }
        }
    }

    rep(i, n) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}

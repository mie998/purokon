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

// sort the graph topologically for DAG (Directed Acyclic Graph)
// https://www.hamayanhamayan.com/entry/2019/01/08/234649
// 使用例:https://atcoder.jp/contests/dp/submissions/10559518
struct TopologicalSort {
    vector<vector<int>> edge;
    vector<int> sorted;
    TopologicalSort(int n) : edge(n), sorted(n) {}

    void add_edge(int a, int b) {
        edge[a].push_back(b);
    }

    bool visit(int v, vector<int> &order, vector<int> &color) {
        color[v] = 1;
        for (int u : edge[v]) {
            if (color[u] == 2) continue;
            if (color[u] == 1) return false;
            if (!visit(u, order, color)) return false;
        }
        order.push_back(v);
        color[v] = 2;
        return true;
    }

    // false: cannot sort (not DAG)
    bool sort() {
        int n = edge.size();
        vector<int> color(n);
        for (int u = 0; u < n; u++)
            if (!color[u] && !visit(u, sorted, color)) return false;
        reverse(sorted.begin(), sorted.end());
        return true;
    }
};

int dp[100005];
bool used[100005];

int dfs(int i, vii &edge) {
    if (used[i]) return dp[i];
    used[i] = true;
    for (auto e : edge[i]) {
        chmax(dp[i], dfs(e, edge) + 1);
        used[e] = true;
    }
    return dp[i];
}

int main() {
    int n, m;
    cin >> n >> m;
    TopologicalSort ts(n);
    vii E(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ts.add_edge(a, b);
        E[a].push_back(b);
    }
    if (!ts.sort()) out("bikkuri!");

    for_each(cu, ts.sorted) for_each(to, E[cu]) chmax(dp[to], dp[cu] + 1);
    int ans = 0;
    rep(i, n) chmax(ans, dp[i]);
    cout << ans << endl;
}

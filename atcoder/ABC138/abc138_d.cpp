#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
typedef long long ll;
typedef pair<ll, ll> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 100 + 5;
const int MAX_N = 1e5 * 2 + 5;

using Graph = vector<vector<int>>;
vector<bool> seen;
vector<int> ans;

void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v])
            continue; // next_v が探索済だったらスルー
        ans[next_v] += ans[v];
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    Graph G(n);
    seen.assign(n, false);
    ans.assign(n, 0);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
    }
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        a--;
        ans[a] += b;
    }
    dfs(G, 0);
    rep(i, n) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

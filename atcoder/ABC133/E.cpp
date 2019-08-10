#include <bits/stdc++.h>
using namespace std;

// adjecent-list
struct Edge {
    int to;
    int weight;
};
const int MAX = 1e5 + 5;
vector<Edge> Graph[MAX];
bool checked[MAX];
int color[MAX];
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9;

int dfs(const int K, const vector<Edge> &graph, int from, int now) {
    int availableColor;
    if (from == -1) {
        availableColor = K - 1;
    } else {
        availableColor = K - 2;
    }
    if (availableColor < K) {
        return 0;
    }
    for (auto e : graph[now]) {
        if (e.to == from) continue;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Graph[a].push_back(Edge(b, 1));
        Graph[b].push_back(Edge(a, 1));
    }
    ll ans = dfs(k, Graph, -1, 0);
    cout << ans % M << endl;
}

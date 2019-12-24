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
typedef pair<int, int> P;
typedef vector<vector<int>> Graph;
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 100000 + 5;
const int MAX_N = 1e5 + 5;

struct edge {
    int to, cost;
};
int n;
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする。
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> V;
    int start;
    cin >> start;
    Graph tree(n);
    rep(i, V) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(edge{b, c});
    }
    dijkstra(start);
    rep(i, n) {
        cout << d[i] << endl;
    }
}

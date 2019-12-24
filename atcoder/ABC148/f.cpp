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
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;

struct edge {
    int to, cost;
};
int V;
vector<edge> G[MAX_V];
vector<bool> is_leaf(MAX_N, false);
int d_takahashi[MAX_V];
int d_aoki[MAX_V];

void dijkstra_takahashi(int s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする。
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d_takahashi, d_takahashi + V, INF);
    d_takahashi[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d_takahashi[v] < p.first) continue;
        for (int i = 0; i < (int)G[v].size(); i++) {
            edge e = G[v][i];
            if (d_takahashi[e.to] > d_takahashi[v] + e.cost) {
                d_takahashi[e.to] = d_takahashi[v] + e.cost;
                que.push(P(d_takahashi[e.to], e.to));
            }
        }
    }
}

void dijkstra_aoki(int s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする。
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d_aoki, d_aoki + V, INF);
    d_aoki[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d_aoki[v] < p.first) continue;
        for (int i = 0; i < (int)G[v].size(); i++) {
            edge e = G[v][i];
            if (d_aoki[e.to] > d_aoki[v] + e.cost) {
                d_aoki[e.to] = d_aoki[v] + e.cost;
                que.push(P(d_aoki[e.to], e.to));
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    V = n;
    int takahashi, aoki;
    cin >> takahashi >> aoki;
    takahashi--;
    aoki--;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(edge{b, 1});
        G[b].push_back(edge{a, 1});
    }
    rep(i, n) {
        if (G[i].size() == 1) is_leaf[i] = true;
    }
    dijkstra_takahashi(takahashi);
    dijkstra_aoki(aoki);
    int m = 0;
    rep(i, n) {
        if (is_leaf[i] && (d_takahashi[i] < d_aoki[i])) {
            if (m < d_aoki[i] - 1) {
                m = d_aoki[i] - 1;
            }
        }
    }
    cout << m << endl;
}

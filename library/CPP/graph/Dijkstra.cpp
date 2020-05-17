int prev[MAX_V]; // 最短路の直前の頂点
int d[MAX_V];
bool used[MAX_V];

//　始点sから各頂点への最短距離をもとめる
void dijkstra(int s) {
    fill(d, d + V, INF);
    fill(used, used + V, false);
    fill(prev, prev + V, -1);
    d[s] = 0;

    while (true) {
        int v = -1;
        for (int u = 0; u < V; u++) {
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if (v == -1) break;
        used[v] = true;

        for (int u = 0; u < V; u++) {
            if (d[u] > d[v] + cost[v][u]) {
                d[u] = d[v] + cost[v][u];
                prev[u] = v;
            }
        }
    }
}

// 頂点tへの最短路
vector<int> get_path(int t) {
    vector<int> path;
    for (; i != -1; t = prev[v])
        path.push_back(t); // tがsになるまでprev[t]を辿っていく
    // このままだとt->sの順になっているので逆順にする。
    reverse(path.begin(), path.end());
    return path;
}
// すべての辺のコストが等しい時、単一始点最短路は幅優先探索で求めることができる。この場合はダイクストラ法のpriority_queueはqueueと同じ振る舞いをする。

// https://drken1215.hatenablog.com/entry/2019/02/15/141000
// グラフ
using Edge = pair<int, long long>;  // {辺の行き先, 重み}
using Graph = vector<vector<Edge>>; // グラフ
// 使われうる辺集合
set<pair<int, int>> use;

// s を始点とする Dijkstra
vector<long long> Dijkstra(const Graph &G, int s) {
    vector<long long> dist((int)G.size(), INF);
    vector<vector<int>> prev((int)G.size()); // prev[v] := v から復元できる辺たち
    dist[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
    que.push({0, s});
    while (!que.empty()) {
        auto cur = que.top();
        que.pop();
        long long cur_dist = cur.first;
        int v = cur.second;
        if (cur_dist > dist[v]) continue; // 効く枝刈り
        for (auto e : G[v]) {
            if (dist[e.first] > dist[v] + e.second) {
                dist[e.first] = dist[v] + e.second;
                que.push({dist[e.first], e.first});

                // 復元のための
                prev[e.first].clear();
                prev[e.first].push_back(v);
            } else if (dist[e.first] == dist[v] + e.second) {
                prev[e.first].push_back(v);
            }
        }
    }

    // 使われうる辺集合
    for (int v = 0; v < (int)G.size(); ++v) {
        for (auto u : prev[v]) {
            use.insert(make_pair(min(u, v), max(u, v)));
        }
    }
    return dist;
}

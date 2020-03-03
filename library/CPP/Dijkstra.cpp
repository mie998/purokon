int prev[MAX_V]; // 最短路の直前の頂点

//　始点sから各頂点への最短距離をもとめる
void difkstra(int s) {
    fill(d, d + V, INF);
    fill(used, used + V, false);
    fill(prev, pref + V, -1);
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

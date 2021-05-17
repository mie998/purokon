int pre[MAX_N];
long long d[MAX_N];
bool seen[MAX_N];
struct Edge {
    int to;
    long long cost;
};
// require: cost value is positive
// O(nlog|v|)
void dijkstra(int s, vector<vector<Edge>> &graph) {
    fill(pre, pre + MAX_N, -1);
    fill(seen, seen + MAX_N, false);
    fill(d, d + MAX_N, INF);

    auto comPair = [](const P one, const P two) {
        return one.second > two.second;
    };
    // que(v, distance)
    priority_queue<P, vector<P>, decltype(comPair)> que(comPair);
    que.emplace(0, 0);
    d[0] = 0;
    seen[0] = true;

    while (!que.empty()) {
        int u = que.top().first;
        que.pop();

        for (auto e : graph[u]) {
            int v = e.to;
            int c = e.cost;

            if (not seen[v] and d[v] > d[u] + c) {
                d[v] = d[u] + c;
                pre[v] = u;
                que.emplace(v, d[v]);
            }
        }
        seen[u] = true;
    }
};

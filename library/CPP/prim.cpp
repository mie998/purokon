// O(|E|log|V|)
typedef pair<int, int> P; // (cst, to)
vector<P> G[MAX];
bool used[MAX];

int prim() {
    priority_queue<P, vector<P>, greater<P>> que;
    memset(used, 0, sizeof(used));
    que.push(P(0, 0));
    int ret = 0;
    while (!que.empty()) {
        int cst = que.top().first, v = que.top().second;
        que.pop();
        if (used[v]) continue;
        used[v] = 1;
        ret += cst;
        for (int i = 0; i < G[v].size(); i++)
            que.push(P(G[v][i].first, G[v][i].second));
    }
    return ret;
}

// kruskal の使い方
#define MAX_E 10000

struct edge {
    int u;
    int v;
    int cost;
};

vector<edge> es;
int V, E;

// Union Find
struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);

        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
};

bool comp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

int kruskal() {
    sort(es.begin(), es.end(), comp);
    UnionFind uf = UnionFind(V);
    int res = 0;
    for (auto &e : es) {
        if (!uf.same(e.u, e.v)) {
            uf.unionSet(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int from, to, cst;
        cin >> from >> to >> cst; // from, to はそれぞれ -1 必須かも
        es.push_back(edge{from, to, cst});
        es.push_back(edge{to, from, cst});
    }
    cout << kruskal() << endl;
}

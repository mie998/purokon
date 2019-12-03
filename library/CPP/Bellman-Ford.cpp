// Bellman-Ford とその使い方
// 頂点fromから頂点toへのcostの辺
struct edge {
    int from, to, cost;
};
const int MAX_E = 1e5 + 5;
const int MAX_V = 1e5 + 5;
vector<edge> es;

int d[MAX_V]; // 最短距離
int V, E;     // Vは頂点数、Eは辺数

// s番目の頂点から各頂点への最短距離を求める。
void shortest_path(int s) {
    for (int i = 0; i < V; i++)
        d[i] = INF;
    d[s] = 0;
    while (true) {
        bool update = false;
        for (auto e : es) {
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}

// trueなら負の経路が存在する
bool find_negative_loop() {
    memset(d, 0, sizeof(d));

    for (int i = 0; i < V; i++) {
        for (auto e : es) {
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;

                //　n回目にも更新があるならば負の経路が存在する
                if (i == V - 1) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> V >> E;
    int s;
    cin >> s;
    for (int i = 0; i < E; i++) {
        int x, y, cst;
        cin >> x >> y >> cst;
        es.push_back(edge{x, y, cst});
    }
    if (find_negative_loop())
        cout << "NEGATIVE CYCLE" << endl;
    else {
        shortest_path(s);
        for (int i = 0; i < V; i++) {
            cout << d[i] << endl;
        }
    }
}

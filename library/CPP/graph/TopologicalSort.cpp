// sort the graph topologically for DAG (Directed Acyclic Graph)
// https://www.hamayanhamayan.com/entry/2019/01/08/234649
// 使用例:https://atcoder.jp/contests/dp/submissions/10559518
struct TopologicalSort {
    vector<vector<int>> edge;
    vector<int> sorted;
    TopologicalSort(int n) : edge(n), sorted(n) {}

    void add_edge(int a, int b) {
        edge[a].push_back(b);
    }

    bool visit(int v, vector<int> &order, vector<int> &color) {
        color[v] = 1;
        for (int u : edge[v]) {
            if (color[u] == 2) continue;
            if (color[u] == 1) return false;
            if (!visit(u, order, color)) return false;
        }
        order.push_back(v);
        color[v] = 2;
        return true;
    }

    // false: cannot sort (not DAG)
    bool sort() {
        int n = edge.size();
        vector<int> color(n);
        for (int u = 0; u < n; u++)
            if (!color[u] && !visit(u, sorted, color)) return false;
        reverse(sorted.begin(), sorted.end());
        return true;
    }
};

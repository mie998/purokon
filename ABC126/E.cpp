#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000 //10^5

int par[MAX_N];       // 親
int rank_tree[MAX_N]; // 木の深さ

// n要素で初期化
void init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        rank_tree[i] = 0;
    }
}

// 木の根を求める
int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

// xとyの属する集合を併合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rank_tree[x] < rank_tree[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rank_tree[x] == rank_tree[y]) rank_tree[x]++;
    }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n, m;
    int result = 0;
    int temp1, temp2, temp3;
    cin >> n >> m;
    vector<int> x, y;
    init(n);
    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2 >> temp3;
        x.push_back(temp1);
        y.push_back(temp2);
    }
    for (int i = 0; i < m; i++) {
        unite(x[i], y[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (i == find(i)) result++;
    }
    cout << result << endl;
    return 0;
}

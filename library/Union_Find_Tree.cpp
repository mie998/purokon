#define MAX_N 100000 //10^5

int par[MAX_N];       // 親
int rank_tree[MAX_N]; // 木の深さ

// n要素で初期化
void init(int n) {
    for (int i = 1; i <= n; i++) { // 1-index. 注意。
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
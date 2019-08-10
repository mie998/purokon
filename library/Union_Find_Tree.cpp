#define MAX_N 100000 //10^5

int par[MAX_N]; // 親
int rnk[MAX_N]; // 木の深さ

// n要素で初期化
void init(int n) {
    for (int i = 1; i <= n; i++) { // 1-index. 注意。
        par[i] = i;
        rnk[i] = 0;
    }
}

// 木の根を求める
int root(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = root(par[x]);
    }
}

// xとyの属する集合を併合
void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;

    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y) {
    return root(x) == root(y);
}

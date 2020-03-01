#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define CYES cout << "Yes" << endl
#define CNO cout << "No" << endl
#define SPC(x) cout << fixed << setprecision(x)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
typedef pair<int, int> P;
typedef complex<ld> Point;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

//qiita.com/drken/items/cce6fc5c579051e64fab
template <class Abel>
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> size;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n);
        rank.resize(n);
        size.resize(n);
        diff_weight.resize(n);
        for (int i = 0; i < n; ++i)
            par[i] = i, rank[i] = 0, size[i] = 1, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    int get_size(int x) {
        return size[root(x)];
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        size[x] = size[y] = size[x] + size[y];
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind<int> uf(n);
    vii friends(n);
    vii blocks(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        friends[a].push_back(b);
        friends[b].push_back(a);
        uf.merge(a, b, 1);
    }
    // rep(i, n) {
    //     debug(uf.get_size(i));
    // }
    rep(i, k) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        blocks[a].push_back(b);
        blocks[b].push_back(a);
    }
    rep(i, n) {
        int ans = uf.get_size(i);
        ans -= 1 + friends[i].size();
        for (auto e : blocks[i]) {
            if (uf.issame(i, e)) ans--;
        }
        out(max(0, ans));
    }
    return 0;
}

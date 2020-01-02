#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Graph;
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 100000 + 5;
const int MAX_N = 1e5 + 5;

int n;
bool seen[MAX_V];
ll familiy_size[MAX_V];
Graph tree;
// save memory
int mod = 1e9 + 7;
long modpow(long m, long p) {
    if (p == 0) return 1;
    if (p % 2)
        return m * modpow(m, p - 1) % mod;
    else {
        long res = modpow(m, p / 2);
        return res * res % mod;
    }
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

void dfs(ll v) {
    if (seen[v]) return;
    seen[v] = true;
    for (auto e : tree[v]) {
        if (!seen[e]) {
            dfs(e);
            familiy_size[v] += familiy_size[e];
        }
    }
}

int main() {
    cin >> n;
    tree.resize(n);
    vector<P> edges;
    rep(i, n) {
        familiy_size[i] = 1;
    }
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
        edges.emplace_back(a, b);
    }
    dfs(0);
    ll exp_count = 0;
    ll deno = modpow(2, n);
    for (auto e : edges) {
        ll x_e = abs(familiy_size[e.first] - familiy_size[e.second]);
        exp_count += ((modpow(2, x_e) - 1) % mod * (modpow(2, n - x_e) - 1) % mod) % mod;
        exp_count++;
        debug(x_e);
        debug(exp_count);
    }
    ll nume = ((exp_count + mod) - (n * modpow(2, n - 1)) % mod) % mod;
    ll ans = nume * modinv(deno, mod) % mod;

    out(ans);
}

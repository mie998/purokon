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
typedef pair<ll, ll> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 100 + 5;
const int MAX_N = 1e5 + 5;

// save memory
int MOD = 1e9 + 7;
long modpow(long m, long p) {
    if (p == 0) return 1;
    if (p % 2)
        return m * modpow(m, p - 1) % MOD;
    else {
        long res = modpow(m, p / 2);
        return res * res % MOD;
    }
}

int main() {
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    priority_queue<int> que;
    rep(i, n) {
        ll temp;
        cin >> temp;
        que.push(temp);
    }
    rep(i, m) {
        ll t = que.top();
        que.pop();
        t /= 2;
        que.push(t);
    }
    while (!que.empty()) {
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
}

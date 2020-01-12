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
typedef long long ll;
typedef pair<int, int> P;
typedef list<list<int>> Graph;
const int MOD = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 100000 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

long long fac[MAX_N];

long long fact(int n) {
    if (n == 1) return fac[n] = 1;
    if (fac[n]) return fac[n];
    return fac[n] = (fact(n - 1) * n) % MOD;
}

int main() {
    ll n;
    ll ans = 0;
    cin >> n;
    vector<ll> x(n);
    fact(n);
    rep(i, n) {
        cin >> x[i];
    }
    vector<ll> dist;
    repeat(i, 1, n) {
        dist.push_back(x[i] - x[i - 1]);
    }
    rep(i, n - 1) {
        ll sum = 0;
        rep(j, i + 1) {
            sum += fact(n - 1) / (j + 1);
        }
        ans += (dist[i] * sum) % MOD;
        ans %= MOD;
    }
    out(ans);
}

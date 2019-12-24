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
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 1000 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    ll n, k;
    ll ans = 0;
    ll sum = 0;
    cin >> n >> k;
    vector<ll> piled_sum(n);
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
        piled_sum[i] = sum;
    }
    rep(i, n) {
        auto iter = lower_bound(piled_sum.begin() + i, piled_sum.end(), k);
        ans += piled_sum.end() - iter;
        k += a[i];
    }
    out(ans);
}

// common include
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
const int M = 1e9 + 7;
const int INF = 1e9;

// typedef
typedef pair<int, int> P;
typedef tuple<int, int, int> P3;
typedef vector<vector<int>> Graph;

int main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    vector<ll> a(n), f(n);
    rep(i, n) scanf("%lld", &a[i]);
    rep(i, n) scanf("%lld", &f[i]);
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<int>());
    ll worst = 1e12;
    ll ans = worst / 2;
    while (true) {
        ll sum = 0;
        rep(i, n) {
            sum += max((ll)0, a[i] - ans / f[i]);
        }
        if (sum <= k) {
            if (worst == ans) break;
            worst = ans;
            ans /= 2;
        } else {
            if (worst - ans <= 1) break;
            ans = (worst + ans) / 2;
        }
    }
    out(worst);
}

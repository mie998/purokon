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

int main() {
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);
    vector<ll> cusum(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    ll sum = 0;
    rep(i, n) {
        sum += a[i];
        cusum[i] = sum;
    }
    ll ans = 0;
    ll border = a[p - 1];
    rep(i, n) {
        if (i < p) {
            ans++;
        } else if (a[i] + m < border) {
            continue;
        } else {
            ll idx = i + 1;
            ll key_area = n - idx + p;
            if (v <= key_area) {
                ans++;
            } else {
                ll distr = m * (v - key_area);
                ll max = a[i] + m;
                ll p_sum = cusum[i - 1] - cusum[p - 2];
                if (max * (i - p + 1) - p_sum >= distr)
                    ans++;
            }
        }
    }
    out(ans);
}

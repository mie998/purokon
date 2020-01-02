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
typedef vector<vector<int>> Graph;
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 100000 + 5;
const int MAX_N = 1e5 + 5;

ll n, m;
vector<ll> a;
bool valid(ll x) {
    ll cnt = 0;
    rep(i, n) {
        auto iter = lower_bound(all(a), x - a[i]);
        cnt += a.end() - iter;
    }
    if (cnt >= m) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> n >> m;
    a.resize(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    vector<ll> cusum(n, 0);
    rep(i, n) {
        if (i == 0) cusum[0] = a[0];
        cusum[i] = cusum[i - 1] + a[i];
    }

    ll lb = 0, ub = 1e10;
    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        if (valid(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    ll cnt = 0, ans = 0, tmp = 0;
    rep(i, n) {
        auto iter = lower_bound(all(a), lb - a[i]);
        cnt = a.end() - iter;
        tmp += cnt;
        ans += cusum[a.end() - a.begin() - 1] - cusum[iter - a.begin() - 1];
        ans += cnt * a[i];
    }
    ll diff = m - tmp;
    ans += diff * lb;
    out(ans);
}

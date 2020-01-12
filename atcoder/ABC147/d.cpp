using namespace std;
#include <bits/stdc++.h>

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
const int INF = 1e9;
const int MAX_V = 1000 + 5;
const int MAX_N = 1e5 + 5;

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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    ll ans = 0;
    sort(a.begin(), a.end(), greater<int>());
    ll k = ceil(log2(a[0]));
    for (ll i = 0; i <= k; i++) {
        ll cnt_zero = 0;
        ll cnt_one = 0;
        for (auto e : a) {
            if ((e >> i) & 1) {
                cnt_one += 1;
            } else {
                cnt_zero += 1;
            }
        }
        ans += (cnt_one * cnt_zero) * modpow(2, i);
        ans %= M;
    }
    cout << ans << endl;
}

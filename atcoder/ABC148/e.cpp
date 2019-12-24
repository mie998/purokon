#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
typedef unsigned long long ll;
typedef pair<int, int> P;
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 1000 + 5;
const int MAX_N = 1e5 + 5;

ll modpow(ll m, ll p) {
    if (p == 0) return 1;
    if (p % 2)
        return m * modpow(m, p - 1);
    else {
        ll res = modpow(m, p / 2);
        return res * res;
    }
}

int main() {
    ll n;
    cin >> n;
    if (n % 2 == 0) {
        ll ans = 0;
        for (ll i = 1; i <= 25; i++) {
            ans += n / (modpow(5, i) * 2);
        }
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }
}

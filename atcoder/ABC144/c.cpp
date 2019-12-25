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
const ll INF = 1e12;
// typedef
typedef pair<int, int> P;
typedef tuple<int, int, int> P3;

bool is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1; // exclude 1
}

// make vector of divisor O(sqrt(n))
vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> div = divisor(n);
    ll ans = INF;
    for (auto e : div) {
        ans = min(ans, ((e - 1) + (n / e - 1)));
    }
    out(ans);
}

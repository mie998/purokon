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
const double PI = acos(-1);

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> half(n);
    vector<ll> counts;
    rep(i, n) {
        half[i] = a[i] / 2;
        ll cnt_2 = 0;
        ll b = half[i];
        while (b % 2 == 0) {
            cnt_2++;
            b /= 2;
        }
        counts.push_back(cnt_2);
    }
    bool consistency = true;
    repeat(i, 1, n) {
        if (counts[i - 1] != counts[i]) consistency = false;
    }
    ll div = 1;
    rep(i, n) div = lcm(div, half[i]);
    if (div > m || !consistency) {
        out(0);
        return 0;
    }
    ll ans = m / (div * 2);
    if (ans != (m + div) / (div * 2)) ans++;
    out(ans);
}

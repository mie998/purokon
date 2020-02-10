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
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> Point;
typedef vector<vector<int>> Graph;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

int main() {
    ll n;
    cin >> n;
    vector<P> area(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        ll from = max(0LL, a - b);
        ll to = min((ll)INF, a + b);
        area[i] = P(to, from);
    }
    int ans = 0;
    sort(all(area));
    // // how to use priority_queue on pair
    // auto comPair = [](const P &firstElof, const P &secondElof) {
    //     if (firstElof.second != secondElof.second)
    //         return firstElof.second < secondElof.second;
    //     else
    //         return firstElof.first > secondElof.first;
    // };
    // priority_queue<P, vector<P>, decltype(comPair)> que(comPair);
    ll t = 0;
    rep(i, n) {
        if (t <= area[i].second) {
            ans++;
            t = area[i].first;
        }
    }
    out(ans);
    return 0;
}

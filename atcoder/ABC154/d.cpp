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
#define CYES cout << "Yes" << endl
#define CNO cout << "No" << endl
#define SPC(x) cout << fixed << setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
typedef pair<int, int> P;
typedef complex<ld> Point;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

int main() {
    ll n, k;
    cin >> n >> k;
    vl p(n);
    rep(i, n) cin >> p[i];
    vl cusum(n);
    cusum[0] = p[0];
    ll ma = 0;
    repeat(i, 1, n) cusum[i] = cusum[i - 1] + p[i];
    repeat(i, k, n) ma = max(ma, cusum[i] - cusum[i - k]);
    if (n == k)
        ma = cusum[n - 1];
    // debug(ma);
    SPC(12);
    double ans = (ma + k) / 2.0;
    out(ans);
    return 0;
}

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
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))

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
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll a_c = (a - 1) / c;
    ll a_d = (a - 1) / d;
    ll a_cd = (a - 1) / (lcm(c, d));
    ll b_c = b / c;
    ll b_d = b / d;
    ll b_cd = b / (lcm(c, d));
    // debug(a_c);
    // debug(a_d);
    // debug(a_cd);
    // debug(b_c);
    // debug(b_d);
    // debug(b_cd);
    ll ans = (b - a + 1) - ((b_c - a_c) + (b_d - a_d) - (b_cd - a_cd));
    out(ans);
    return 0;
}

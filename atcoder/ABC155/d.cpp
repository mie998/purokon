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

int main() {
    ll n, k;
    cin >> n >> k;
    vl Z, N, P;
    rep(i, n) {
        ll a;
        cin >> a;
        if (a == 0)
            Z.push_back(a);
        else if (a < 0)
            N.push_back(a);
        else
            P.push_back(a);
    }
    ll AN_size = N.size() * P.size();
    ll AP_size = N.size() * (N.size() - 1) / 2 + P.size() * (P.size() - 1) / 2;
    ll AZ_size = N.size() * Z.size() + P.size() * Z.size();
    // debug(AN_size);
    // debug(AP_size);
    // debug(AZ_size);
    ll ans = 0;
    if (k <= AN_size) {
        vl AN;
        for (int n : N) {
            for (int p : P) {
                AN.push_back(n * p);
            }
        }
        sort(all(AN));
        ans = AN[k];
    } else if (k <= AN_size + AZ_size) {
        ans = 0;
    } else {
        vl AP;
        rep(i, N.size()) {
            repeat(j, i + 1, N.size()) {
                ll n1 = N[i];
                ll n2 = N[j];
                AP.push_back(n1 * n2);
            }
        }
        rep(i, P.size()) {
            repeat(j, i + 1, P.size()) {
                ll p1 = P[i];
                ll p2 = P[j];
                AP.push_back(p1 * p2);
            }
        }
        sort(all(AP));
        ans = AP[k - AN_size - AZ_size];
    }
    out(ans);
    return 0;
}

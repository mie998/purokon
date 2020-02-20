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
    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(all(a));

    ll ub = 1e18, lb = -1e18;
    while (ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        auto is_smaller = [&](ll x) {
            ll cnt = 0;
            rep(i, n) {
                if (a[i] >= 0) {
                    ll l = -1, r = n;
                    while (r - l > 1) {
                        ll o = (l + r) / 2;
                        if (a[i] * a[o] < x) {
                            l = o;
                        } else {
                            r = o;
                        }
                        // debug(l);
                        // debug(r);
                        // debug(o);
                    }
                    cnt += r;
                } else {
                    ll l = -1, r = n;
                    while (r - l > 1) {
                        ll o = (l + r) / 2;
                        if (a[i] * a[o] < x) {
                            r = o;
                        } else {
                            l = o;
                        }
                        // debug(l);
                        // debug(r);
                        // debug(o);
                    }
                    cnt += n - r;
                }

                if (a[i] * a[i] < x) cnt--;
            }
            cnt /= 2;
            return cnt < k;
        };

        // debug(mid);
        if (is_smaller(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    out(lb);
}

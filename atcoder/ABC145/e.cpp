#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i > 0; i--)
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

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// how to use priority_queue on pair

int main() {
    int n, t;
    cin >> n >> t;
    vector<P> a(n);
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
    }

    vii dp1(3050, vi(3050, 0));
    vii dp2(3050, vi(3050, 0));

    rep(i, n) {
        auto p = a[i];
        rep(j, t + 1) {
            if (j + p.first <= t) {
                chmax(dp1[i + 1][j + p.first], dp1[i][j] + p.second);
            }

            chmax(dp1[i + 1][j], dp1[i][j]);

            // debug(i);
            // debug(j);
            // debug(dp1[i][j]);
        }
    }

    reverse(all(a));
    rep(i, n) {
        auto p = a[i];
        rep(j, t + 1) {
            if (j + p.first <= t) {
                chmax(dp2[i + 1][j + p.first], dp2[i][j] + p.second);
            }

            chmax(dp2[i + 1][j], dp2[i][j]);

            // debug(i);
            // debug(j);
            // debug(dp2[i][j]);
        }
    }

    reverse(all(a));
    int ans = 0;
    rep(i, n) {
        rep(j, t) {
            chmax(ans, dp1[i][j] + dp2[n - i - 1][t - 1 - j] + a[i].second);

            // debug(ans);
        }
    }
    out(ans);
    return 0;
}

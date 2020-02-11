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
    auto comPair = [](const P &firstElof, const P &secondElof) {
        return firstElof.first < secondElof.second;
    };
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a), comPair);

    vii dp(3050, vi(3050, 0));
    vector<bool> used(n, false);
    rep(i, n) {
        auto p = a[i];
        used[i] = true;
        rep(j, t + 1) {
            if (j == t - 1) {
                auto idx = n - 1;
                if (used[idx])
                    continue;
                p = a[idx];
                chmax(dp[i + 1][t], dp[i][j] + p.second);
            }

            if (j + p.second <= t) {
                chmax(dp[i + 1][j + p.first], dp[i][j] + p.second);
            }

            chmax(dp[i + 1][j], dp[i][j]);

            debug(i);
            debug(j);
            debug(dp[i][j]);
        }
    }
    out(dp[n][t]);
    return 0;
}

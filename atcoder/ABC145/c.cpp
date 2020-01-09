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

long long fac[MAX_N];

long long fact(int n) {
    if (n == 1) return fac[n] = 1;
    if (fac[n]) return fac[n];
    return fac[n] = (fact(n - 1) * n) % M;
}

int main() {
    int n;
    cin >> n;
    vector<P> v(n, P(0, 0));
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    int perm[n];
    rep(i, n) {
        perm[i] = i;
    }
    double ans = 0;
    do {
        for (int i = 1; i < n; i++) {
            int from = perm[i - 1];
            int to = perm[i];
            ans += sqrt((v[to].first - v[from].first) * (v[to].first - v[from].first) + (v[to].second - v[from].second) * (v[to].second - v[from].second));
        }
    } while (next_permutation(perm, perm + n));
    ans /= fact(n);
    cout << setprecision(12) << ans << endl;
}

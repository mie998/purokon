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
typedef pair<ll, ll> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 100 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    long double mul = 1.0;
    long double plu = 0.0;
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        mul *= (long double)a[i];
    }
    rep(i, n) {
        plu += mul / (long double)a[i];
    }
    long double ans = mul / plu;
    cout << setprecision(16) << ans << endl;
}

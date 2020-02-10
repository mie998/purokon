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
typedef pair<int, int> P;
typedef complex<ld> Point;
typedef vector<vector<int>> Graph;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

int main() {
    ll n, k, s;
    cin >> n >> k >> s;
    vector<ll> ans;
    ll compliment;
    if (s == 1) {
        compliment = 1e9;
    } else {
        compliment = s - 1;
    }
    rep(i, n) {
        if (i < k)
            ans.push_back(s);
        else
            ans.push_back(compliment);
    }
    rep(i, n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}

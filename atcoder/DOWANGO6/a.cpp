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

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> v(n);
    rep(i, n) {
        string s;
        int t;
        cin >> s >> t;
        v[i] = make_pair(s, t);
    }
    string x;
    cin >> x;
    bool lock = true;
    int ans = 0;
    rep(i, n) {
        string s = v[i].first;
        int t = v[i].second;
        if (lock && x == s) {
            lock = false;
            continue;
        }
        if (lock) continue;
        if (!lock) ans += t;
    }
    out(ans);
}

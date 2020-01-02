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
typedef pair<int, int> P;
typedef vector<vector<int>> Graph;
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 100000 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p;
    cin >> t;
    vector<char> formar(n, 'n');
    vector<char> latter(n, 'n');
    rep(i, n) {
        if (i - k >= 0) {
            formar[i] = t[i - k];
        }
        if (i + k < n) {
            latter[i] = t[i + k];
        }
    }
    ll ans = 0;
    rep(i, n) {
        if (formar[i] == 'n') {
            if (t[i] == 'r') {
                ans += p;
            } else if (t[i] == 's') {
                ans += r;
            } else {
                ans += s;
            }
        } else {
            if (formar[i] == t[i] && latter[i] == t[i]) {
                formar[i + k] = 'n';
            } else if (formar[i] == t[i] && latter[i] != t[i]) {
                continue;
            } else {
                if (t[i] == 'r') {
                    ans += p;
                } else if (t[i] == 's') {
                    ans += r;
                } else {
                    ans += s;
                }
            }
        }
    }
    out(ans);
}

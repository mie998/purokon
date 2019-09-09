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
    string s, t;
    cin >> s >> t;
    ll ans = 0;
    vector<vector<int>> alphabets(26);

    int sz_s = s.size();
    int sz_t = t.size();

    rep(i, sz_s) { alphabets[s[i] - 'a'].push_back(i); }
    rep(i, sz_s) { alphabets[s[i] - 'a'].push_back(i + sz_s); }

    int checking_index = 0;
    rep(i, sz_t) {
        int ch = t[i] - 'a';
        if (alphabets[ch].size() == 0) {
            puts("-1");
            return 0;
        }

        checking_index = *lower_bound(alphabets[ch].begin(), alphabets[ch].end(), checking_index) + 1;

        if (checking_index >= sz_s) {
            ans += sz_s;
            checking_index -= sz_s;
        }
    }
    ans += checking_index;
    cout << ans << endl;
}

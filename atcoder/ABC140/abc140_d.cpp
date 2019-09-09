// common include
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
const int M = 1e9 + 7;
const int INF = 1e9;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    if (s[0] == 'L') {
        rep(i, n) {
            if (s[i] == 'R')
                s[i] = 'L';
            else
                s[i] = 'R';
        }
    }

    int ans = 0;
    rep(i, n - 1) {
        if (s[i] == s[i + 1]) ans++;
    }

    int i = 0;
    while (i < n) {
        if (k == 0) break;
        if (s[i] == 'L') {
            while (s[i] == 'L') {
                i++;
            }
            if (i >= n) {
                ans += 1;
                cout << ans << endl;
                return 0;
            }
            ans += 2;
            k--;
            i++;
        }
        if (s[i] == 'R') i++;
    }
    cout << ans << endl;
}

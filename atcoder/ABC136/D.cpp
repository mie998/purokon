#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 300 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n);
    rep(ri, 2) {
        int cnt = 0;
        rep(i, n) {
            if (s[i] == 'R') {
                cnt++;
            } else {
                ans[i - 1] += (cnt + 1) / 2;
                ans[i] += cnt / 2;
                cnt = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        reverse(s.begin(), s.end());
        rep(i, n) {
            if (s[i] == 'L')
                s[i] = 'R';
            else
                s[i] = 'L';
        }
    }
    rep(i, n) cout << ans[i] << " ";
    cout << endl;
}

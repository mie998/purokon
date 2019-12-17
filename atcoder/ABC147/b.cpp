using namespace std;
#include <bits/stdc++.h>

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1000 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    rep(i, n / 2) {
        char a = s[i];
        char b = s[n - 1 - i];
        if (a != b) {
            ans += 1;
        }
    }
    cout << ans << endl;
}

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
    int n; 
    cin >> n;
    vector<int> b(n-1);
    int ans = 0;
    rep(i,n-1) {
        cin >> b[i];
    }
    ans += b[0];
    rep(i, n-2) {
        ans += min(b[i], b[i+1]);
    }
    ans += b.back();
    cout << ans << endl;
}

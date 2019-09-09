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
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    int res = 0;
    rep(i,n) {
        cin >> a[i];
    }
    rep(i,n) {
        cin >> b[i];
    }
    rep(i,n-1) {
        cin >> c[i];
    }
    int curr;
    int prev = -500;
    for (auto e: a) {
        curr = e - 1;
        res += b[curr];
        if ((curr - prev) == 1) res += c[prev];
        prev = curr;
    }
    cout << res << endl;
}

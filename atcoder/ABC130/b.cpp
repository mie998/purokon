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
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 1000 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    int dist = 0;
    int cnt = 0;
    rep(i, n) {
        if (dist <= x) {
            cnt++;
            dist += l[i];
        } else {
            break;
        }
    }
    if (dist <= x) cnt++;
    cout << cnt << endl;
}

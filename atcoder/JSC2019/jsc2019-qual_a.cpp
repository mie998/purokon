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
    int m, d;
    int cnt = 0;
    cin >> m >> d;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= d; j++) {
            if (j < 10 || j > 100) continue;
            int d_1 = j % 10;
            int d_10 = j / 10;
            if (d_1 >= 2 && d_10 >= 2 && i == d_1 * d_10) cnt++;
        }
    }
    cout << cnt << endl;
}

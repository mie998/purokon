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

int a[20];
int x[20][20];
int y[20][20];

int count(int k) {
    if (k == 0) return 0;
    return count(k >> 1) + (k & 1);
}

int main() {
    int n;
    int ans = 0;

    cin >> n;
    repeat(i, 1, n + 1) {
        cin >> a[i];
        repeat(j, 1, a[i] + 1) {
            cin >> x[i][j] >> y[i][j];
        }
    }

    for (int bit = 1; bit < (1 << n); bit++) {
        bool ok = true;
        repeat(i, 1, n + 1) {
            if (!(bit & (1 << (i - 1)))) continue;
            repeat(j, 1, a[i] + 1) {
                if (((bit >> (x[i][j] - 1)) & 1) ^ y[i][j]) ok = false;
            }
        }
        if (ok) ans = max(ans, count(bit));
    }

    cout << ans << endl;
}

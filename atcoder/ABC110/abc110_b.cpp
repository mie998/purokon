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
const int INF = 1e9;
const int MAX_V = 1000 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    int n, m, x, y;
    bool ok = false;
    cin >> n >> m >> x >> y;
    vector<int> X(n), Y(m);
    rep(i, n) cin >> X[i];
    rep(i, m) cin >> Y[i];

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (int i = x + 1; i <= y; i++) {
        if (X.back() < i && Y[0] >= i) {
            ok = true;
        }
    }
    if (ok)
        cout << "No War" << endl;
    else
        cout << "War" << endl;
}

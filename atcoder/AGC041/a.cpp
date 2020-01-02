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
typedef vector<vector<int>> Graph;
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 100000 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll diff = b - a;
    ll ans = 0;
    if (diff % 2 == 0) {
        ans = diff / 2;
    } else {
        ll go_left_round = a - 1;
        ll go_right_round = n - b;
        if (go_left_round >= go_right_round) {
            go_right_round++;
            a += go_right_round;
            ans = (n - a) / 2 + go_right_round;
        } else {
            go_left_round++;
            b -= go_left_round;
            ans = (b - 1) / 2 + go_left_round;
        }
    }
    out(ans);
}

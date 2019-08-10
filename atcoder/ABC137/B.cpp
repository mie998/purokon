#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n) - 1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 100 + 5;
const int MAX_N = 1e6;

int main() {
    int k,x;
    cin >> k >> x;
    if (x - k + 1 < -MAX_N) {
        rep(i, k) {
            cout << -MAX_N + i << " ";
        }
        cout << endl;
    } else if (x + k - 1 > MAX_N) {
        revrep(i, k) {
            cout << MAX_N - i << " ";
        }
        cout << endl;

    } else {
        repeat(i, x - k + 1, x + k) {
            cout << i << " ";
        }
        cout << endl;

    }

}
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

// typedef
typedef pair<int, int> P;
typedef tuple<int, int, int> P3;
typedef vector<vector<int>> Graph;

bool can(int a) {
    if (0 <= a && a <= 9) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < 10; i++) {
        if (n % i == 0) {
            if (can(n / i)) {
                out("Yes");
                return 0;
            }
        }
    }
    out("No");
    return 0;
}

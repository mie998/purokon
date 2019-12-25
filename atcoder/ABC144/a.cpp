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
    int a, b;
    cin >> a >> b;
    if (can(a) && can(b)) {
        cout << a * b << endl;
    } else {
        out(-1);
    }
}

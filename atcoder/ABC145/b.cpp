#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Graph;
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 100000 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2) {
        out("No");
        return 0;
    }
    int j = n / 2;
    rep(i, n / 2) {
        if (s[i] != s[j]) {
            out("No");
            return 0;
        }
        j++;
    }
    out("Yes");
}

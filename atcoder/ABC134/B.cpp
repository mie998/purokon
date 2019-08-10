#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 300 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    int n, d;
    cin >> n >> d;
    d = 2 * d + 1;
    int ans = (n + d - 1) / d;
    cout << ans << endl;
}

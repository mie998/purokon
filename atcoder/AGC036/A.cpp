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
    ll s;
    cin >> s;
    ll x1, x2, x3, y1, y2, y3;
    x1 = y1 = 0;
    y2 = ceil(sqrt(s));
    x3 = ceil(sqrt(s));
    x2 = x3 * y2 - s;
    y3 = 1;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}

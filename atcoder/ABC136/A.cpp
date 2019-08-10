#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat (i, a, b) for (int i = (a); i < (b); i++)
#define rep (i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 300 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= b + c) {
        cout << 0 << endl;
    } else {
        cout << c - a + b << endl;
    }
}

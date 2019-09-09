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
const int MAX = 1e5 + 50;
typedef pair<int, int> P;

// factorial
long long fac[MAX];

long long fact(int n) {
    if (n == 1) return fac[n] = 1;
    if (fac[n]) return fac[n];
    return fac[n] = (fact(n - 1) % M * n) % M;
}

void invalid() {
    cout << 0 << endl;
    exit(0);
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (s[0] == 'W') invalid();

    ll ans = 1;
    int l = 1;
    int r = 0;
    int curr = 0;
    repeat(i, 1, 2 * n) {
        if (s[i - 1] == s[i]) {
            curr ^= 1;
        }

        if (curr == 1) {
            ans *= (l - r) % M;
            ans %= M;
        }

        if (curr == 0)
            l++;
        else
            r++;

        if (r > l) invalid();
    }
    if (l != r) invalid();

    ans *= fact(n) % M;
    ans %= M;
    cout << ans << endl;
}

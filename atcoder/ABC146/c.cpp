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
const ll INF = 1e9;
const int MAX_V = 1000 + 5;
const int MAX_N = 1e5 + 5;

ll a, b, x;
ll digit(ll n) {
    ll cnt = 0;
    while (n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

ll can_buy(ll n) {
    if (a * n + b * digit(n) <= x) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> a >> b >> x;
    ll max = INF;
    ll min = 0;
    while (1) {
        if (max - min <= 1) {
            if (can_buy(max))
                cout << max << endl;
            else
                cout << min << endl;
            return 0;
        }
        ll mean = (max + min) / 2;
        if (can_buy(mean)) {
            min = mean;
        } else {
            max = mean;
        }
    }
}

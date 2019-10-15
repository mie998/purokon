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
typedef pair<ll, ll> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 100 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    vector<int> points(n);
    map<int, int> m;
    rep(i, q) {
        int temp;
        cin >> temp;
        temp--;
        m[temp]++;
    }
    rep(i, n) {
        if ((k - (q - m[i])) > 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

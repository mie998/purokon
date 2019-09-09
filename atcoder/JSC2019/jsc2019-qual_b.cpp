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

bool comPair(const P &firstElof, const P &secondElof) {
    return firstElof.second > secondElof.second;
}

int main() {
    int n;
    ll k;
    ll ans = 0;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<int> minorThanInQ;
    rep(i, n) {
        int c = 0;
        repeat(j, i, n) {
            if (a[i] > a[j]) {
                c++;
            }
        }
        minorThanInQ.push_back(c);
    }

    vector<int> minorThan;
    rep(i, n) {
        int c = 0;
        rep(j, n) {
            if (a[i] > a[j]) {
                c++;
            }
        }
        minorThan.push_back(c);
    }

    ll sum = (((k - 1) * k) / 2) % M;
    rep(i, n) {
        ans += (minorThan[i] * sum) % M;
        ans %= M;
        ans += (minorThanInQ[i] * k) % M;
        ans %= M;
    }
    cout << ans << endl;
}

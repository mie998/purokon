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
const int INF = 1e9;
const int MAX_V = 1000 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    string s, t;
    cin >> s >> t;
    int S = s.size();
    int T = t.size();
    map<char, int> ma_s, ma_t;
    rep(i, S) {
        ma_s[s[i]]++;
    }
    rep(i, T) {
        ma_t[t[i]]++;
    }

    map<int, int> numOfS, numOfT;
    rep(i, 26) {
        char c = 'a' + i;
        numOfS[ma_s[c]]++;
    }
    rep(i, 26) {
        char c = 'a' + i;
        numOfT[ma_t[c]]++;
    }

    if (numOfS == numOfT)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

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
    int n;
    string s;
    cin >> n >> s;
    vector<int> cand;
    int length = 0 int l1, l2;
    string stat;
    string fini;
    rep(i, n) {
        stat = s[i];
        l1 = i;
        repeat(j, i + 1, n) {
            fini = s[j];
            l2 = j;
            while ((stat == fini) && (i + length < j) && l2 <= n) {
                l1++;
                l2++;
                length++;
                stat += s[l1];
                fini += s[l2];
            }
            cand.push_back(length);
            stat = s[i];
            l1 = i;
            length = 0;
        }
    }
    sort(cand.begin(), cand.end(), greater<int>());
    cout << cand[0] << endl;
}

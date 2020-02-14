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
#define CYES cout << "Yes" << endl
#define CNO cout << "No" << endl
#define SPC(x) cout << fixed << setprecision(x)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
typedef pair<int, int> P;
typedef complex<ld> Point;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

int main() {
    string s;
    cin >> s;
    int n = s.length();
    string goal_1 = "";
    string goal_2 = "";
    rep(i, n) {
        if (i % 2 == 0) {
            goal_1 += '0';
            goal_2 += '1';
        } else {
            goal_1 += '1';
            goal_2 += '0';
        }
    }
    int haming_1 = 0;
    int haming_2 = 0;
    rep(i, n) {
        if (s[i] != goal_1[i]) haming_1++;
        if (s[i] != goal_2[i]) haming_2++;
    }
    out(min(haming_1, haming_2));
    return 0;
}

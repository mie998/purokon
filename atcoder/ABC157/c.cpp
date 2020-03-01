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

int char_to_int(char c) {
    return c - '0';
}

int main() {
    int n, m;
    cin >> n >> m;
    vi s(m);
    vi c(m);
    rep(i, m) {
        cin >> s[i] >> c[i];
    }
    int ans = -1;
    if (n == 1) {
        bool ok = true;
        string num = "0";
        rep(j, m) {
            if (s[j] != 1 || c[j] != 0) ok = false;
        }
        if (ok) {
            ans = 0;
            out(ans);
            return 0;
        }
    }

    repeat(i, pow(10, n - 1), pow(10, n)) {
        bool ok = true;
        string num = to_string(i);
        rep(j, m) {
            if (char_to_int(num[s[j] - 1]) != c[j]) ok = false;
        }
        if (ok) {
            ans = i;
            break;
        }
    }
    out(ans);

    return 0;
}

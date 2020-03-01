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
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<set<int>> v(27);
    rep(i, n) {
        rep(j, 26) {
            if (s[i] == char('a' + j))
                v[j].insert(i);
        }
    }

    rep(i, q) {
        int query_distinction;
        cin >> query_distinction;
        if (query_distinction == 1) {
            int idx;
            char c;
            cin >> idx >> c;
            idx--;
            rep(j, 27) {
                if (v[j].find(idx) != v[j].end())
                    v[j].erase(idx);
            }
            v[c - 'a'].insert(idx);
        } else {
            int l, r;
            int cnt = 0;
            cin >> l >> r;
            l--, r--;
            rep(j, 27) {
                auto lb = v[j].lower_bound(l);
                if (lb == v[j].end()) continue;
                // debug(char(j + 'a'));
                // debug(*lb);
                if (*lb <= r) cnt++;
            }
            out(cnt);
        }
    }

    return 0;
}

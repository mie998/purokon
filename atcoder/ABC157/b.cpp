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
    vii card(3, vi(3));
    vector<vector<bool>> card_check(3, vector<bool>(3, false));
    rep(i, 3) {
        rep(j, 3) {
            cin >> card[i][j];
        }
    }
    int n;
    cin >> n;
    vi b(n);
    rep(i, n) cin >> b[i];
    rep(i, n) {
        rep(j, 3) {
            rep(k, 3) {
                if (card[j][k] == b[i]) {
                    card_check[j][k] = true;
                }
            }
        }
    }
    if ((card_check[0][0] && card_check[1][1] && card_check[2][2]) ||
        (card_check[0][0] && card_check[1][0] && card_check[2][0]) ||
        (card_check[0][0] && card_check[0][1] && card_check[0][2]) ||
        (card_check[1][0] && card_check[1][1] && card_check[1][2]) ||
        (card_check[0][1] && card_check[1][1] && card_check[2][1]) ||
        (card_check[2][0] && card_check[2][1] && card_check[2][2]) ||
        (card_check[0][2] && card_check[1][2] && card_check[2][2]) ||
        (card_check[0][2] && card_check[1][1] && card_check[2][0])) {
        CYES;
    } else {
        CNO;
    }

    return 0;
}

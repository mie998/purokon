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
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool first_bit = s[0] - '0';
    vi nums(n);
    int m = 0;
    s += 'p'; // padding bit
    repeat(i, 1, n + 1) {
        int num = 1;
        while (s[i] == s[i - 1]) {
            num++;
            i++;
        }
        nums[m] = num;

        // debug(m);
        // debug(nums[m]);
        m++;
    }

    vl accum(m + 1, 0);
    accum[0] = nums[0];
    repeat(i, 1, m) {
        accum[i] = accum[i - 1] + nums[i];

        // debug(i);
        // debug(accum[i]);
    }

    ll ans = 0;
    rep(i, m) {
        bool bit;
        if (i % 2 == 0) {
            bit = first_bit;
        } else {
            bit = !first_bit;
        }
        if (bit) {
            ans = max(ans, accum[min(m - 1, 2 * k + i)] - (i - 1 < 0 ? 0 : accum[i - 1]));
        } else {
            ans = max(ans, accum[min(m - 1, 2 * k - 1 + i)] - (i - 1 < 0 ? 0 : accum[i - 1]));
        }
        // debug(bit);
        // debug(ans);
    }
    out(ans);
    return 0;
}

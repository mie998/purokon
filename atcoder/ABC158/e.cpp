#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define for_each(e, v) for (auto &e : v)
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
const int INF = __INT_MAX__;               // 2^31 - 1
const long long INFLL = __LONG_LONG_MAX__; // 2^61 - 1
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

int MOD;
long long modpow(long long m, long long p) {
    if (p == 0) return 1;
    if (p % 2)
        return m * modpow(m, p - 1) % MOD;
    else {
        long res = modpow(m, p / 2);
        return res * res % MOD;
    }
}

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    MOD = p;
    cin >> s;
    reverse(all(s));
    ll ans = 0;
    if (p == 2 || p == 5) {
        rep(i, n) {
            if ((s[i] - '0') % p == 0)
                ans += n - i;
        }
    } else {
        map<int, ll> cnt;
        ll sum = 0;
        rep(i, n) {
            int d = (s[i] - '0') * modpow(10, i);
            sum = (sum + d) % p;
            cnt[sum]++;
        }

        rep(i, p) {
            ans += cnt[i] * (cnt[i] - 1) / 2;
        }
    }
    out(ans);
}

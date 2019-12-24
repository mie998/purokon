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
const ll INF = 1e9;
const int MAX_V = 1000 + 5;
const int MAX_N = 1e5 + 5;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1; // exclude 1
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    rep(i, n) cin >> a[i];
    ll left, right;
    left = right = 0;
    ll sum = a[0];
    ll ans = 0;
    for (left = 0; left < n; left++) {
        while (left > right) {
            right++;
            sum += a[right];
        }
        if (left > 0) {
            sum = max((ll)0, sum - a[left - 1]);
        }
        while (right < n && sum < k) {
            right++;
            sum += a[right];
        }
        if (sum >= k) {
            ans += n - right;
        }
    }
    out(ans);
}

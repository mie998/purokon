#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n) - 1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 100 + 5;
const int MAX_N = 1e5 + 5;

bool dp[MAX_N];

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    rep(i, n) {
        cin >> v[i];
        sum += v[i];
    }
    dp[0] = true;
    int ans = 0;
    rep(i, n){
        irrep(j, sum + 1) {
            if (v[i] + j <= MAX_N)
                dp[v[i] + j] |= dp[j];
        }
    }
    rep(i,sum + 1) {
        if (dp[i]) ans++;
    } 
    printf("%d\n", ans);
}

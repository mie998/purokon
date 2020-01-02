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
typedef vector<vector<int>> Graph;
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 100000 + 5;
const int MAX_N = 1e5 + 5;


// Eratosthenes O(nloglog(n))
int prime[MAX_N];     // i番目の素数
bool is_prime[MAX_N]; // i が素数か否か　
// n以下の素数の数を返す
int sieve(int n) {
    int p = 0;
    for (int i = 0; i <= n; i++)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            // i の倍数全消去
            for (int j = 2 * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return p;
}

int main() {
    int n;
    cin >> n;
    sieve(100050);
    int i = n;
    while(1) {
        if (is_prime[i]) {
            out(i);
            return 0;
        }
        i++;
    }
}

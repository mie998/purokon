#include <bits/stdc++.h>
using namespace std;

int main() {
    long long l, r;
    int i, j, k;
    const int MOD = 2019;
    cin >> l >> r;
    if (r - l > 2019) {
        cout << 0 << endl;
        return 0;
    }
    l = l % MOD;
    r = r % MOD;
    int ans = 19999;
    for (i = l; i < r; i++) {
        for (j = i + 1; j <= r; j++) {
            ans = min(i * j % MOD, ans);
        }
    }
    cout << ans << endl;
}

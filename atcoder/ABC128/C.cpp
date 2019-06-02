#include <bits/stdc++.h>
using namespace std;

int bitCount(int bits) {
    int cnt = 0;
    for (int mask = 1; mask != 0; mask <<= 1) {
        if ((bits & mask) != 0)
            ++cnt;
    }
    return cnt;
}

int main() {
    int n, m;
    int i, k, j, s;
    int ans = 0;
    vector<vector<int>> vec;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> k;
        vector<int> a;
        for (j = 0; j < k; j++) {
            cin >> s;
            a.push_back(s);
        }
        vec.push_back(a);
    }
    vector<int> p;
    for (i = 0; i < m; i++) {
        cin >> k;
        p.push_back(k);
    }

    bool ok = true;
    for (int S = 1; S < (1 << n); S++) {
        for (i = 0; i < m; i++) {
            for (j = 0; j < vec[i].size(); j++) {
                S &= (1 << vec[i][j]);
            }
            int z = bitCount(S);
            if (z % 2 != p[i]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}

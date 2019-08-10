#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ": " << x << endl
typedef pair<int, int> P;
// sort by P.first (asd)
bool comPair(const P &firstElof, const P &secondElof) {
    return firstElof.second < secondElof.second;
}

int main() {
    int n, i, j, k;
    bool check = false;
    vector<int> vec;
    cin >> n;
    int sum = 0;
    for (i = 0; i < n; i++) {
        cin >> k;
        sum += k;
        vec.emplace_back(k);
    }
    vector<int> ans(n);
    ans[0] = sum;
    for (i = 1; i < n; i += 2) {
        ans[0] -= 2 * vec[i];
    }
    for (i = 0; i < n; i++) {
        ans[i + 1] = vec[i] * 2 - ans[i];
    }
    for (i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

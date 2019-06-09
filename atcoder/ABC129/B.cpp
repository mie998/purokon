#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, j, k;
    vector<int> w, results;
    int sum1, sum2;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> k;
        w.push_back(k);
    }
    for (i = 1; i < n; i++) {
        sum1 = sum2 = 0;
        for (j = 0; j < n; j++) {
            if (j + 1 <= i) {
                sum1 += w[j];
            } else {
                sum2 += w[j];
            }
        }
        results.push_back( abs(sum1 - sum2));
    }
    sort(results.begin(), results.end());
    cout << results[0] << endl;
}
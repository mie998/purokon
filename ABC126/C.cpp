#include <bits/stdc++.h>
using namespace std;

int main() {
    double rate = 0.0;
    int n, k, i;
    cin >> n >> k;

    for (i = 1; i <= n; i++) {
        double temp = 1.0 / n;
        int roop = i;
        while (roop < k) {
            roop *= 2;
            temp /= 2;
        }
        rate += temp;
    }

    cout << setprecision(12) << rate << endl;

    return 0;
}

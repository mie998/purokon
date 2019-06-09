#include <bits/stdc++.h>
using namespace std;

long long fibn[100000];
int fib(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
    if (fibn[n] != 0) {
        return fibn[n];
    }
    return fibn[n] = (fib(n - 1) + fib(n - 2));
}

int main() {
    long long Fin = 1000000007;
    int n, m, i, j, k;
    long long result;
    vector<int> v;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> k;
        v.push_back(k);
    }
    result = 1;
    result = (result * fib(v[0] - 1));
    for (i = 1; i < m; i++) {
        if (v[i] - v[i - 1] >= 2) {
            result = (result * fib(v[i - 1] - v[i] - 2));
        } else {
            cout << 0 << endl;
            return 0;
        }
    }
    result = (result * fib(n - v[m - 1] - 1));
    cout << result % Fin << endl;
}

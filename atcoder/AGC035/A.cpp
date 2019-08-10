#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 300 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    int n;
    vector<ll> a;
    bool allZero = true;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        if (temp != 0) allZero = false;
        a.push_back(temp);
    }
    if (allZero) {
        cout << "Yes" << endl;
        return 0;
    }
    if (!(n % 3 == 0)) {
        cout << "No" << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    if (n == 3) {
        if (a[0] ^ a[1] ^ a[2] == 0) {
            cout << "Yes" << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i < n / 3; i++) {
        if (a[i - 1] != a[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = n / 3 + 1; i < 2 * n / 3; i++) {
        if (a[i - 1] != a[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 2 * n / 3 + 1; i < n; i++) {
        if (a[i - 1] != a[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    int x = a[0] ^ a[n / 3] ^ a[2 * n / 3];
    if (x) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}

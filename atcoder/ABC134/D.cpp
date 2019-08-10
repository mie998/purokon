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

vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int m = 0;
    vector<int> b(n, 0);
    vector<bool> push(n, false);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            push[i] = true;
            vector<int> div = divisor(i + 1);
            for (int j = div.size() - 1; j >= 0; j--) {
                auto e = div[j];
                b[e - 1] = (b[e - 1] + 1) % 2;
            }
        } else
            continue;
    }
    for (auto e : push) {
        if (e) m++;
    }
    cout << m << endl;
    for (int i = 0; i < n; i++) {
        if (push[i])
            cout << i + 1 << " ";
        else
            continue;
    }
    cout << endl;
}

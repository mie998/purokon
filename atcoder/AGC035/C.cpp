#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 300 + 5;
const int MAX_N = 1e5 + 5;

int pow(int a, int b) {
    if (b == 0)
        return 1;
    else
        return a * pow(a, b - 1);
}

int main() {
    int n;
    cin >> n;
    bool canMake = true;
    vector<P> ans;
    for (int i = 0; i < 20; i++) {
        if (n == pow(2, i)) canMake = false;
    }
    if (!canMake) {
        cout << "No" << endl;
        return 0;
    }
    ans.emplace_back(P(1, 2));
    for (int i = 2; i < n; i += 2) {
        ans.emplace_back(P(i + 1, 1 + n));
        ans.emplace_back(P(1 + n, i + n));
        ans.emplace_back(P(i, i + 1));
        ans.emplace_back(P(i + n, i + n + 1));
    }
    if (n % 2 == 0) {
        int y = 3 ^ 1 ^ n;
        ans.push_back(P(n, y + n));
        ans.push_back(P(3, 2 * n));
    }
    cout << "Yes" << endl;
    for (auto e : ans) {
        cout << e.first << " " << e.second << endl;
    }
}

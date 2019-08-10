#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat (i, a, b) for (int i = (a); i < (b); i++)
#define rep (i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 300 + 5;
const int MAX_N = 1e5 + 5;

int main() {
    int n, t, i;
    cin >> n;
    vector<int> height;
    vector<bool> lock(n, false);
    if (n == 1) {
        puts("Yes");
        return 0;
    }
    for (i = 0; i < n; i++) {
        cin >> t;
        height.push_back(t);
    }
    for (i = 0; i < n; i++) {
        if (i >= 1 && height[i - 1] >= height[i])
            continue;
        else
            height[i]--;
    }
    for (i = 0; i < n - 1; i++) {
        if (height[i] > height[i + 1]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
}

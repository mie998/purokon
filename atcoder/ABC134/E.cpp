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
    cin >> n;
    vector<int> a(n);
    int rst = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, less<int>> colors;
    colors.push(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] <= colors.top()) {
            rst++;
            colors.push(a[i]);
        } else {
            colors.pop();
            colors.push(a[i]);
        }
    }
    cout << rst << endl;
}

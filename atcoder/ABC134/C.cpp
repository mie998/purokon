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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (a[i] == sorted[0])
            cout << sorted[1] << endl;
        else
            cout << sorted[0] << endl;
    }
}

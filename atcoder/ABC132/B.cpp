#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main() {
    int i, j, k;
    int n;
    cin >> n;
    vector<int> p(n);
    int cnt = 0;
    for (i = 0; i < n; i++)
        cin >> p[i];
    for (i = 1; i < n - 1; i++) {
        int a = p[i - 1];
        int b = p[i];
        int c = p[i + 1];
        if (a == b && b > c || b == c && b > a) cnt++;
        if (a < b && b < c || c < b && b < a) cnt++;
        if (a == c && b > a) cnt++;
    }
    cout << cnt << endl;
}

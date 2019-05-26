#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, a_min, query, a, b;
    long long min_1, min_2;
    cin >> n;
    scanf("%d%d", &a, &b);
    a_min = a;
    min_1 = b;
    for (i = 1; i < n; i++) {
        scanf("%d", &query);
        if (query == 2) {
            min_2 = min_1;
            cout << min_1 << " " << a_min << endl;
        } else {
            scanf("%d%d", &a, &b);
            a_min = min(a_min, a);
            min_1 = min_1 + abs(a_min - a) + b;
        }
    }
    return 0;
}

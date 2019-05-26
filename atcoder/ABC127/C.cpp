#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back(0);
    }
    int temp1, temp2;
    vector<int> a, b;
    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        a.push_back(temp1);
        b.push_back(temp2);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int de = b.front();
    int dc = a.back();
    int count;
    if (de >= dc)
        count = de - dc + 1;
    else
        count = 0;

    cout << count << endl;

    return 0;
}

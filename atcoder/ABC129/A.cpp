#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v;
    v.push_back(a + b);
    v.push_back(a + c);
    v.push_back(b + a);
    sort(v.begin(), v.end());
    cout << v[0] << endl;
}

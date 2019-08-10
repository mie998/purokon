#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main() {
    int i, j, k;
    int n;
    cin >> n;
    vector<int> vec(n);
    for (i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    int frt = n / 2 - 1;
    int fre = n / 2;
    cout << vec[fre] - vec[frt] << endl;
}

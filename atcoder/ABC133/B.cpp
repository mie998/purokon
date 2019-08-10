#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++) {
        vector<int> v(d);
        for (int j = 0; j < d; j++) {
            cin >> v[j];
        }
        vec.push_back(v);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < d; k++) {
                sum += (vec[i][k] - vec[j][k]) * (vec[i][k] - vec[j][k]);
            }
            for (int l = 0; l < 200; l++) {
                if (sum == l * l) res++;
            }
        }
    }
    cout << res << endl;
}

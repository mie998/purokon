#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main() {
    int t, n, m;
    int i, j, k;
    cin >> t >> n;
    vector<int> vec1, vec2;
    for (i = 0; i < n; i++) {
        cin >> k;
        vec1.push_back(k);
    }
    cin >> m;
    for (j = 0; j < m; j++) {
        cin >> k;
        vec2.push_back(k);
    }
    vector<bool> check(m, false);
    int pos = 0;
    for (i = 0; i < vec2.size(); i++) {
        for (j = pos; j < vec1.size(); j++) {
            pos++;
            if (vec1[j] <= vec2[i] && vec2[i] <= vec1[j] + t) {
                check[i] = true;
                break;
            }
        }
    }
    bool complete = true;
    for (auto b : check)
        if (!b) complete = false;
    if (complete)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

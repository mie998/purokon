#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int cnt = 0;
    int i, j, k;
    cin >> s;
    vector<string> v;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            string c;
            c += 'A';
            for (j = i + 1; j < s.size(); j++) {
                if (s[j] == 'A') {
                    c += 'A';
                    if (j == (s.size() - 1)) {
                        v.push_back(c);
                        i = j;
                    }
                    continue;
                } else if (s[j] == 'B' && s[j + 1] == 'C') {
                    c += 'X';
                    j++;
                    if (j == (s.size() - 1)) {
                        v.push_back(c);
                        i = j;
                    }
                    continue;
                } else {
                    i = j;
                    v.push_back(c);
                    break;
                }
            }
        }
    }

    for (i = 0; i < v.size(); i++) {
        for (j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 'A') {
                for (k = j; k < v[i].size(); k++) {
                    if (v[i][k] == 'X') cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
}

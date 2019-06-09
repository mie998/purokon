#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int cnt = 0;
    int cnt_a = 0;
    int i, j, k;
    cin >> s;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            cnt_a++;
        } else {
            if (i + 1 < s.size() && s[i] == 'B' && s[i + 1] == 'C') {
                cnt += cnt_a;
                i++;
            } else
                cnt_a = 0;
        }
    }

    cout << cnt << endl;
}

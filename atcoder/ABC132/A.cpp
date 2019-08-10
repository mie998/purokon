#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main() {
    int i, j, k;
    string s;
    cin >> s;
    int cnt = 0;
    char a = s[0];
    char b = s[1];
    char c = s[2];
    char d = s[3];
    if (a == b) cnt++;
    if (a == c) cnt++;
    if (a == d) cnt++;
    if (b == c) cnt++;
    if (b == d) cnt++;
    if (c == d) cnt++;
    if (cnt == 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int sa, sb;
    int a, b, c, d;
    cin >> s;
    a = s[0] - '0';
    b = s[1] - '0';
    c = s[2] - '0';
    d = s[3] - '0';
    sa = 10 * a + b;
    sb = 10 * c + d;

    if (1 <= sa && sa <= 12) {
        if (1 <= sb && sb <= 12) {
            cout << "AMBIGUOUS" << endl;
        } else {
            cout << "MMYY" << endl;
        }
    } else {
        if (1 <= sb && sb <= 12) {
            cout << "YYMM" << endl;
        } else {
            cout << "NA" << endl;
        }
    }
    return 0;
}

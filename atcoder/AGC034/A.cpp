#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    cin.tie(0);
    string obstacle = "##";
    string oasis = "...";
    string b_to_d = s.substr(b - 1, d - b);
    string a_to_c = s.substr(a - 1, c - a);
    string a_to_d = s.substr(a - 1, d - a);
    if (c < d) {
        if (a_to_c.find(obstacle) == string::npos && b_to_d.find(obstacle) == string::npos)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else {
        b_to_d = s.substr(b - 2, d - b + 3);
        if (a_to_c.find(obstacle) == string::npos && b_to_d.find(obstacle) == string::npos && b_to_d.find(oasis) != string::npos)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

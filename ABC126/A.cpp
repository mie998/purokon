#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    string s;
    cin >> N >> K >> s;
    char c = s[K - 1];
    s[K - 1] = tolower(c);
    cout << s << endl;
    return 0;
}

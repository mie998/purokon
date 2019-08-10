#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 300 + 5;
const int MAX_N = 1e5 + 5;

void join(char c, string &s) {
    int index = s.find(c);
    if (index == -1) {
        s += c;
    } else {
        s.erase(index);
    }
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<char> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    vector<string> ans;
    int cir;
    for (int i = 0; i < n; i++) {
        join(a[i], s);
    }
    if (s == "") {
        cout << "" << endl;
        return 0;
    }
    ans.push_back(s);
    for (int i = 2; i <= n + 2; i++) {
        for (int j = 0; j < a.size(); j++) {
            join(a[j], s);
        }
        ans.push_back(s);
        if (s.empty()) {
            cir = i;
            break;
        }
    }
    int mod = (k - 1) % cir;
    string res = ans[mod];
    for (auto e : res) {
        cout << e << " ";
    }
    cout << endl;
}

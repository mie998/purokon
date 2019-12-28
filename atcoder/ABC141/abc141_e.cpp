#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
typedef long long ll;
typedef pair<ll, ll> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 100 + 5;
const int MAX_N = 1e5 + 5;

// Z-algorithm: O(n)
// 文字列が与えられた時、各 i について「S と S[i..|S|-1] の最長共通接頭辞の長さ」を記録した配列 A を O(|S|) で構築するアルゴリズム
// https://snuke.hatenablog.com/entry/2014/12/03/214243
vector<int> A(MAX_N, 0);
int m = 0;
int Z_algorithm(string S) {
    A[0] = S.size();
    int i = 1, j = 0;
    while (i < S.size()) {
        while (i + j < S.size() && S[j] == S[i + j])
            ++j;
        A[i] = j;
        if (j <= i) m = max(A[i], m);
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < S.size() && k + A[k] < j)
            A[i + k] = A[k], ++k;
        i += k;
        j -= k;
    }
    return m;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> counts;
    rep(i, n) {
        string subst = s.substr(i, n - i);
        int m = Z_algorithm(subst);
        counts.push_back(m);
    }
    sort(counts.begin(), counts.end(), greater<int>());
    out(counts[0]);
}

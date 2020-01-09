#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Graph;
const int M = 1e9 + 7;
const ll INF = 1e9;
const int MAX_V = 100000 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

int main() {
    int n, t;
    cin >> n >> t;
    vector<P> v;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    auto comPair = [](const P &firstElof, const P &secondElof) {
        if ((double)firstElof.second / double(firstElof.first) == (double(secondElof.second) / double(secondElof.first))) {
            return firstElof.first > secondElof.first;
        } else {
            return (double)firstElof.second / (double)(firstElof.first) < (double)(secondElof.second) / (double)(secondElof.first);
        }
    };
    sort(v.begin(), v.end(), comPair);
    int score = 0;
    int num = 0;
    while (v.size() > 0) {
        if (num >= v.size() - 1) break;
        auto p = v.back();
        if (p.first >= t) {
            v.insert(v.begin(), p);
            v.pop_back();
            num++;
        } else {
            v.pop_back();
            score += p.second;
            t -= p.first;
        }
        debug(t);
        debug(v.size());
    }
    if (v.size() == 0) {
        out(score);
        return 0;
    }
    auto comPair2 = [](const P &firstElof, const P &secondElof) {
        return firstElof.second > secondElof.second;
    };
    sort(v.begin(), v.end(), comPair2);
    score += v.front().second;
    debug(v.front().second);
    out(score);
}

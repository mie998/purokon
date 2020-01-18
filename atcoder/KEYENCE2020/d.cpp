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
typedef long double ld;
typedef pair<int, int> P;
typedef complex<ld> Point;
typedef vector<vector<int>> Graph;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

struct card {
    int pos;
    int neg;
    int idx;
};

void replace(card &x, card &y) {
    swap(x.idx, y.idx);
    swap(x.pos, y.neg);
    swap(x.neg, y.pos);
}

int main() {
    int n;
    cin >> n;
    // vector<card> x;
    // int ans = 0;
    // rep(i, n) {
    //     cin >> x[i].pos >> x[i].neg;
    //     x[i].idx = i;
    // }
    vector<int> v(n);
    vector<int> l(n);
    rep(i, n) {
        if (i % 2 == 0) {
            cin >> v[i];
        } else {
            cin >> l[i];
        }
    }
    rep(i, n) {
        if (i % 2 == 0) {
            cin >> l[i];
        } else {
            cin >> v[i];
        }
    }
    sort(all(v));
    sort(all(l));
    bool ok = true;
    rep(i, n - 1) {
        if (i % 2) {
            if (v[i] < l[i + 1])
                ok = false;
        } else {
            if (l[i] < v[i + 1])
                ok = false;
        }
    }
    if (ok)
        return 0;
    else
        out(-1);
    return 0;
}

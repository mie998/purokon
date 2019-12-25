// common include
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
const int M = 1e9 + 7;
const int INF = 1e9;

// typedef
typedef pair<int, int> P;
typedef tuple<int, int, int> P3;
typedef vector<vector<int>> Graph;
#define PI 3.14159265358979

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    if (x > a * a * b / 2) {
        double tan = a * a * a / (2 * (a * a * b - x));
        cout << setprecision(12) << 90 - (atan(tan) * 180 / PI) << endl;
    } else {
        double tan = 2 * x / (b * b * a);
        cout << setprecision(12) << 90 - (atan(tan) * 180 / PI) << endl;
    }
}

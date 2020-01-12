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
  int n, m;
  cin >> n >> m;
  vector<int> p(m);
  vector<string> s(m);
  rep(i, m) cin >> p[i] >> s[i];
  int ac_cnt = 0;
  int pena_cnt = 0;
  vector<int> acc(n, 0);
  vector<bool> lock(n, false);
  rep(i, m) {
    int num = p[i] - 1;
    string res = s[i];
    if (res == "AC" && !lock[num]) {
      ac_cnt++;
      lock[num] = true;
      pena_cnt += acc[num];
    } else {
      acc[num]++;
    }
  }
  cout << ac_cnt << " " << pena_cnt << endl;
}

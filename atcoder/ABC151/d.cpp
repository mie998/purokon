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

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
char maze[23][23];
bool flag[23][23];
int ans[23][23];
int h, w;

// void print(vector<vector<int>> &v) {
//     for (int i = 0; i < v.size(); i++) {
//         for (int j = 0; j < v[i].size(); j++) {
//             debug(v[i][j]);
//         }
//     }
// }

int bfs(P start, P goal) {
    memset(flag, false, sizeof(flag));
    memset(ans, 0, sizeof(ans));
    queue<P> que;
    flag[start.first][start.second] = 1;
    que.push(P(start.first, start.second));
    while (!que.empty()) {
        P p = que.front();
        que.pop();
        rep(i, 4) {
            int x = p.second + dx[i];
            int y = p.first + dy[i];
            if (0 <= x && x <= w && 0 <= y && y <= h && !flag[y][x] &&
                maze[y][x] == '.') {
                flag[y][x] = 1;
                ans[y][x] = ans[p.first][p.second] + 1;
                que.push(P(y, x));
            }
        }
    }
    return ans[goal.first][goal.second];
}

int main() {
    cin >> h >> w;
    rep(i, h) {
        rep(j, w) { cin >> maze[i][j]; }
    }
    printArray(maze);
    int res = 0;
    P start;
    P goal;
    rep(i, h) {
        rep(j, w) {
            rep(l, h) {
                rep(m, w) {
                    if (maze[i][j] == '.' && maze[l][m] == '.') {
                        start = P(i, j);
                        goal = P(l, m);
                        res = max(res, bfs(start, goal));
                    }
                }
            }
        }
    }
    out(res);
}

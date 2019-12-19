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
typedef pair<int, int> P;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1000 + 5;
const int MAX_N = 1e5 + 5;

bool seen[100020];

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    map<P, int> edge_color_map;
    vector<P> edges;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        edges.emplace_back(a, b);
    }
    vector<int> color(n, 0);
    queue<int> que;
    seen[0] = true;
    que.push(0);
    int max_degree = 0;
    while (!que.empty()) {
        int top = que.front();
        que.pop();
        vector<int> next_vertexes = v[top];
        int curr = 1;
        for (int e : next_vertexes) {
            if (seen[e]) continue;
            que.push(e);
            if (curr == color[top]) curr++;
            edge_color_map[make_pair(top, e)] = curr;
            color[e] = curr;
            max_degree = max(max_degree, curr);
            curr++;
        }
        seen[top] = true;
    }
    cout << max_degree << endl;
    for (auto e : edges) {
        cout << edge_color_map[e] << endl;
    }
}

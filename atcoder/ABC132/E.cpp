#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9;

int main() {
    int n, m, s, t;
    int i, j, k;
    cin >> n >> m;
    vector<P> edge(m);
    for (i = 0; i < m; i++) {
        cin >> j >> k;
        edge[i] = P(j, k);
    }
    cin >> s >> t;
    vector<int> dist(n, INF);
    for (i = 0; i < m; i++) {
        vector<int> starts;
    }
}

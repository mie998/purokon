#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, i, j, k, temp;
    scanf("%d%d", &n, &m);
    priority_queue<int, vector<int>, greater<int>> que;
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        que.push(temp);
    }

    int count, num;

    for (i = 0; i < m; i++) {
        scanf("%d%d", &count, &num);
        if (que.top() >= num)
            continue;
        else {
            for (j = 0; j < count; j++) {
                que.pop();
                que.push(num);
                if (que.top() >= num) continue;
            }
        }
    }

    long long result = 0;

    for (i = 0; i < n; i++) {
        result += que.top();
        que.pop();
    }
    cout << result << endl;

    return 0;
}

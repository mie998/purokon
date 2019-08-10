#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9;
#define debug(x) cout << #x << ": " << x << endl

string X = "";
string Y = "";

// ランダム塩基列の生成
string random_base(int length) {
    string base = "";
    char base_selector[] = {'A', 'G', 'C', 'T'};
    random_device r;
    mt19937 mt(r());
    uniform_int_distribution<> rand(0, 3);
    for (int i = 0; i < length; i++) {
        base += base_selector[rand(mt)];
    }
    return base;
}

// Smith-Waterman algorithm
void SmithWaterman(int gap, int match, int mismatch, string &s1, string &s2) {
    int i, j, k;
    int row = s1.length();
    int col = s2.length();
    vector<vector<int>> matrix; // 基本となるスコア配列
    int S[row][col];            // 文字列一致判定用配列
    P ptr[row][col];            // ポインタ格納用配列
    for (i = 0; i <= row; i++) {
        vector<int> v;
        for (j = 0; j <= col; j++) {
            v.push_back(0);
        }
        matrix.push_back(v);
    }
    // s1[i] と s2[j] が一致するか判定
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            if (s1[i - 1] == s2[j - 1])
                S[i][j] = match;
            else
                S[i][j] = mismatch;
        }
    }
    // ポインタの初期化
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            ptr[i][j] = P(INF, INF);
        }
    }
    // 動的計画
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            int v1 = matrix[i - 1][j - 1] + S[i][j];
            int v2 = matrix[i - 1][j] + gap;
            int v3 = matrix[i][j - 1] + gap;
            int v4 = 0;
            // ポインタ,表を更新する　
            if (v1 >= v2 && v1 >= v3 && v1 >= v4) { // v1が最大
                matrix[i][j] = v1;
                ptr[i][j] = P(i - 1, j - 1);
            } else if (v2 > v1 && v2 >= v3 && v2 >= v4) { // v2が最大
                matrix[i][j] = v2;
                ptr[i][j] = P(i - 1, j);
            } else if (v3 > v1 && v3 > v2 && v3 >= v4) { // v3が最大
                matrix[i][j] = v3;
                ptr[i][j] = P(i, j - 1);
            } else { // v4が最大
                matrix[i][j] = v4;
                // ptr[i][j]は nullptr のまま
            }
        }
    }
    // 表中の最大要素を取り出す
    P max_ptr = P(INF, INF);
    int max_val = 0;
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_ptr = P(i, j);
            }
        }
    }
    // 文字列の復元
    int now_row = max_ptr.first;
    int now_col = max_ptr.second;
    int prev_row = INF;
    int prev_col = INF;
    do {
        if (now_row == INF || now_col == INF) break;
        if (now_row == prev_row) {
            X += "-";
        } else {
            X += s1[now_row - 1];
        }
        if (now_col == prev_col) {
            Y += "-";
        } else {
            Y += s2[now_col - 1];
        }
        // prev_ および now_ の更新
        prev_row = now_row;
        prev_col = now_col;
        now_row = ptr[now_row][now_col].first;
        now_col = ptr[now_row][now_col].second;
    } while (true);
}

int main() {
    int gap, match, mismatch;
    gap = -1;
    match = 1;
    mismatch = -1;
    string s1, s2;
    s1 = random_base(10);
    s2 = random_base(10);
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    SmithWaterman(gap, match, mismatch, s1, s2);
    cout << "X: " << X << endl;
    cout << "Y: " << Y << endl;
}

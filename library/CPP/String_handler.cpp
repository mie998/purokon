const int MAX_N = 1e5;
// Morris_Pratt: O(n)
// 文字列 S が与えられたときに、各iについて「文字列S[0..i-1]の接頭辞と接尾辞が最大何文字一致しているか」を記録した配列を O(|S|)で構築するアルゴリズム
// https://snuke.hatenablog.com/entry/2014/12/01/235807
vector<int> A(MAX_N, 0);
void MP(string S) {
    A[0] = -1;
    int j = -1;
    for (int i = 0; i < S.size(); i++) {
        while (j >= 0 && S[i] != S[j])
            j = A[j];
        j++;
        A[i + 1] = j;
    }
}

// Knuth_Morris_Pratt: O(log(n))
// 文字列 S が与えられたときに、各iについて「文字列S[0..i-1]の接頭辞と接尾辞が最大何文字一致しているか」を記録した配列を O(log|S|)で構築するアルゴリズム
// http://potetisensei.hatenablog.com/entry/2017/07/10/174908
vector<int> A(MAX_N, 0);
void KMP(string S) {
    A[0] = -1;
    int j = -1;
    for (int i = 0; i < S.size(); i++) {
        while (j >= 0 && S[i] != S[j])
            j = A[j];
        j++;
        if (S[i + 1] == S[j])
            A[i + 1] = A[j];
        else
            A[i + 1] = j;
    }
}

// Manacher: O(n)
// 文字列が与えられた時、各 i について「文字 i を中心とする最長の回文の半径」を記録した配列 R を O(|S|) で構築するアルゴリズム
// https://snuke.hatenablog.com/entry/2014/12/02/235837
vector<int> R(MAX_N, 0);
void Manacher(string S) {
    int i = 0, j = 0;
    while (i < S.size()) {
        while (i - j >= 0 && i + j < S.size() && S[i - j] == S[i + j])
            ++j;
        R[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < S.size() && k + R[i - k] < j)
            R[i + k] = R[i - k], ++k;
        i += k;
        j -= k;
    }
}

// Z-algorithm: O(n)
// 文字列が与えられた時、各 i について「S と S[i..|S|-1] の最長共通接頭辞の長さ」を記録した配列 A を O(|S|) で構築するアルゴリズム
// https://snuke.hatenablog.com/entry/2014/12/03/214243
vector<int> A(MAX_N, 0);
void Z_algorithm(string S) {
    A[0] = S.size();
    int i = 1, j = 0;
    while (i < S.size()) {
        while (i + j < S.size() && S[j] == S[i + j])
            ++j;
        A[i] = j;
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
}

#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
//以下は全て https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361 を参考にしている。
//普通のbit全探索
int main() {
    int n = 5;

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1 << n); ++bit) {
        /* bit で表される集合の処理を書く */
    }
}

//n個の要素の集合のうち要素数がkのもののみをbit全探索する
int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

//使用例
int main() {
    int n = 5; // {0, 1, 2, 3, 4} の部分集合を考える
    int k = 3;

    int bit = (1 << k) - 1; // bit = {0, 1, 2}
    for (; bit < (1 << n); bit = next_combination(bit)) {
        /* ここに処理を書く */
    }
}

//部分集合のbit全探索　使用例
int main() {
    int n = 10;
    int A = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7); // {A = {2, 3, 5, 7}

    for (int bit = A;; bit = (bit - 1) & A) {
        /* ここに処理を書く */

        // 最後の 0 で break
        if (!bit) break;
    }
}

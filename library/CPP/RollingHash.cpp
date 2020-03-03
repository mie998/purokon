// MOD固定,基数乱択ローリングハッシュ
// import from https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
// 使用例 https://atcoder.jp/contests/abc141/submissions/10514553
struct RollingHash {
    const unsigned long long MASK30 = (1ULL << 30) - 1;
    const unsigned long long MASK31 = (1ULL << 31) - 1;
    const unsigned long long MODL = (1ULL << 61) - 1;
    const unsigned long long POSITIVIZER = MODL * ((1ULL << 3) - 1);
    const unsigned long long MAX_LENGTH = 500000ULL;
    unsigned int Base;
    vector<unsigned long long> powMemo;
    vector<unsigned long long> hash;

    RollingHash(string s) : powMemo(MAX_LENGTH + 1), hash(s.length() + 1) {
        // 基数を乱数で決定 129 <= Base <= INT_MAX
        unsigned int mi = 129;
        unsigned int range = INT_MAX - mi + 1;
        srand(time(NULL)); // srand でシード値を固定する。同一実行であれば複数の RollingHash が同じ基数を持てる。
        Base = (unsigned int)(rand() % range + mi);
        // powMemo 初期化
        powMemo[0] = 1;
        for (int i = 1; i < (int)powMemo.size(); i++)
            powMemo[i] = CalcMod(Mul(powMemo[i - 1], Base));
        // hashTable 初期化
        for (int i = 0; i < (int)s.length(); i++)
            hash[i + 1] = CalcMod(Mul(hash[i], Base) + s[i]);
    }

    // Hash 値を求める関数
    unsigned long long GetHash(int begin, int length) {
        return CalcMod(hash[begin + length] + POSITIVIZER - Mul(hash[begin], powMemo[length]));
    }

    // オーバーフロー対策
    unsigned long long Mul(unsigned long long l, unsigned long long r) {
        auto lu = l >> 31;
        auto ld = l & MASK31;
        auto ru = r >> 31;
        auto rd = r & MASK31;
        auto middleBit = ld * ru + lu * rd;
        return ((lu * ru) << 1) + ld * rd + ((middleBit & MASK30) << 31) + (middleBit >> 30);
    }

    unsigned long long Mul(unsigned long long l, unsigned int r) {
        auto lu = l >> 31;
        auto rd = r & MASK31;
        auto middleBit = lu * rd;
        return (l & MASK31) * rd + ((middleBit & MASK30) << 31) + (middleBit >> 30);
    }

    // mod 2^61-1を計算する関数
    unsigned long long CalcMod(unsigned long long val) {
        val = (val & MODL) + (val >> 61);
        if (val >= MODL) val -= MODL;
        return val;
    }

    // S[a:], T[b:] の LCP (Longest Common Prefix) を求めるる
    // O(log N)
    unsigned int GetLCP(int a, int b) {
        int len = min((int)hash.size() - a, (int)hash.size() - b);
        int low = 0, high = len;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (GetHash(a, mid) != GetHash(b, mid))
                high = mid;
            else
                low = mid;
        }
        return low;
    }
};

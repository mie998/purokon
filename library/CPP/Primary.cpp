// all input is natural num

// primary judge O(sqrt(n))
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1; // exclude 1
}

// make vector of divisor O(sqrt(n))
vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

// factorization O(sqrt(n))
map<int, int> prime_factor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

// Eratosthenes O(nloglog(n))
int prime[MAX_N];     // i番目の素数
bool is_prime[MAX_N]; // i が素数か否か　
// n以下の素数の数を返す
int sieve(int n) {
    int p = 0;
    for (int i = 0; i <= n; i++)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            // i の倍数全消去
            for (int j = 2 * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return p;
}

struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n) : n(n), f(n + 1) {
        f[0] = f[1] = -1;
        for (long long i = 2; i <= n; i++) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (long long j = i * i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    }
    bool isPrime(int x) { return f[x] == x; }
    vector<int> factorList(int x) {
        vector<int> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<pair<int, int>> factor(int x) {
        vector<int> fl = factorList(x);
        if (fl.size() == 0) return {};
        vector<pair<int, int>> res(1, pair<int, int>(fl[0], 0));
        for (int p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

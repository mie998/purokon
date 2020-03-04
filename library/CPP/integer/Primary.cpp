// all input is natural num

// primary judge O(sqrt(n))
bool is_prime(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1; // exclude 1
}

// make vector of divisor O(sqrt(n))
vector<long long> divisor(long long n) {
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

// factorization O(sqrt(n))
map<long long, long long> prime_factor(long long n) {
    map<long long, long long> res;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

// Eratosthenes O(nloglog(n))
long long prime[MAX_N]; // i番目の素数
bool is_prime[MAX_N];   // i が素数か否か　
// n以下の素数の数を返す
long long sieve(long long n) {
    long long p = 0;
    for (long long i = 0; i <= n; i++)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            // i の倍数全消去
            for (long long j = 2 * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return p;
}

struct Sieve {
    long long n;
    vector<long long> f, primes;
    Sieve(long long n) : n(n), f(n + 1) {
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
    bool isPrime(long long x) { return f[x] == x; }
    vector<long long> factorList(long long x) {
        vector<long long> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<pair<long long, long long>> factor(long long x) {
        vector<long long> fl = factorList(x);
        if (fl.size() == 0) return {};
        vector<pair<long long, long long>> res(1, pair<long long, long long>(fl[0], 0));
        for (long long p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

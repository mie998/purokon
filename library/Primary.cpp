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

MOD = 998244353
N_MAX = int(2 * 1e6 + 1)
two_factors = [1 for _ in range(N_MAX)]


def init():
    global two_factors
    for i in range(1, N_MAX):
        two_factors[i] = (two_factors[i - 1] * 2) % MOD


def main():
    init()
    n, d = map(int, input().split())
    ans = 0
    for i in range(1, n):
        if d <= n - i:
            ans += two_factors[d] * two_factors[i - 1]
            ans %= MOD
        l_max = min(n - i, d - 1)
        l_min = max(1, d - (n - i))
        if l_max >= l_min:
            ans += two_factors[d - 2] * \
                (l_max - l_min + 1) * two_factors[i - 1]
            ans %= MOD
    print(ans * 2 % MOD)


main()

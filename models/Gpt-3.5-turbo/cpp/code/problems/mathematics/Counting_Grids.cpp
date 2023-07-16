
long long pow_mod(long long base, long long exponent, long long mod) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return result;
}

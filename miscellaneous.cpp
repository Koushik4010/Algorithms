
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exponent is odd, multiply base with the result
            result = (result * base) % mod;
        }
        exp = exp >> 1;  // Divide the exponent by 2
        base = (base * base) % mod;  // Square the base
    }
    
    return result;
}

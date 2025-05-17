#include <bits/stdc++.h>
using namespace std;
 
// Global vector for allowed primes (all primes in [2, P]).
vector<unsigned long long> allowed;
 
// dp will store memoized values for F(i, x).
// We pack the state (i, x) into a 64-bit integer:
// use the top 6 bits for i (since i <= 25) and the lower 54 bits for x (since x < 2^54).
unordered_map<unsigned long long, unsigned long long> dp;
 
// We define F(i, x) to be the number of integers <= x
// that have all prime factors among allowed[i ... m-1].
// Base: if i == allowed.size(), then the only number is 1 (if x >= 1).
// Also, if x < 1, then there are no positive integers <= x.
unsigned long long F(int i, unsigned long long x) {
    if(x < 1ULL) return 0ULL;
    if(i == (int)allowed.size()) return 1ULL;
    unsigned long long key = (((unsigned long long)i) << 54) | x; // pack i and x
    if(dp.find(key) != dp.end())
        return dp[key];
    // Option 1: Do not use allowed[i].
    unsigned long long res = F(i+1, x);
    // Option 2: Use at least one copy of allowed[i].
    res += F(i, x / allowed[i]);
    dp[key] = res;
    return res;
}
 
// A simple isPrime function.
bool isPrime(int n) {
    if(n < 2) return false;
    for (int i = 2; (long long)i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    unsigned long long N;
    int P;
    cin >> N >> P;
 
    // Build allowed primes: all primes in the interval [2, P].
    for (int i = 2; i <= P; i++){
        if(isPrime(i))
            allowed.push_back(i);
    }
    // (It is important that we work with allowed primes in ascending order
    // for the recurrence F(i,x) = F(i+1,x) + F(i, x/allowed[i]).)
 
    // Reserve some space for dp to reduce rehashing.
    dp.reserve(1 << 16);
 
    // The answer is the number of P-smooth numbers not exceeding N,
    // which equals F(0, N). (This counts 1 as well.)
    unsigned long long ans = F(0, N);
    cout << ans << "\n";
    return 0;
}

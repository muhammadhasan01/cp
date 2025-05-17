#include <bits/stdc++.h>
using namespace std;
 
// We use __int128 to safely compute products (since N can be as high as 1e18)
typedef __int128 int128;
 
// Fast modular exponentiation mod MOD.
const long long MOD = 998244353;
 
long long modexp(long long base, long long exp, long long mod){
    long long result = 1 % mod;
    base %= mod;
    while(exp > 0){
        if(exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
 
// Global variables for our DP recursion.
 
// We will precompute arrays for powers of 2, 3, 5 up to a certain bound.
vector<int128> p2, p3, p5;
 
// The target state exponents (obtained by factorizing N) and the target product.
int targetA, targetB, targetC;
int128 targetVal;
 
// These bounds (maximum indices we need in our DP arrays) are computed from N.
int max2Bound, max3Bound, max5Bound;
 
// 3D DP table: dp[e2][e3][e5] stores the probability (mod MOD) starting at state (e2,e3,e5).
// We initialize with -1 (not computed).
vector<vector<vector<long long>>> dp;
 
// The modular inverse of 5 modulo MOD.
long long inv5;
 
// DP recursion function.
// The state is (e2,e3,e5) corresponding to the current value = 2^(e2)*3^(e3)*5^(e5).
// Base: if the current product >= targetVal then return 1 if equal and 0 if greater.
long long solve_dp(int e2, int e3, int e5) {
    // Compute current product = 2^(e2)*3^(e3)*5^(e5) using our precomputed arrays.
    int128 cur = p2[e2] * p3[e3] * p5[e5];
    if(cur >= targetVal) {
        return (cur == targetVal) ? 1LL : 0LL;
    }
    if(dp[e2][e3][e5] != -1) return dp[e2][e3][e5];
    
    long long sum = 0;
    // The 5 possible moves:
    // Roll 2: add (1,0,0)
    {
        int ne2 = e2 + 1, ne3 = e3, ne5 = e5;
        sum = (sum + solve_dp(ne2, ne3, ne5)) % MOD;
    }
    // Roll 3: add (0,1,0)
    {
        int ne2 = e2, ne3 = e3 + 1, ne5 = e5;
        sum = (sum + solve_dp(ne2, ne3, ne5)) % MOD;
    }
    // Roll 4: add (2,0,0)
    {
        int ne2 = e2 + 2, ne3 = e3, ne5 = e5;
        sum = (sum + solve_dp(ne2, ne3, ne5)) % MOD;
    }
    // Roll 5: add (0,0,1)
    {
        int ne2 = e2, ne3 = e3, ne5 = e5 + 1;
        sum = (sum + solve_dp(ne2, ne3, ne5)) % MOD;
    }
    // Roll 6: add (1,1,0)
    {
        int ne2 = e2 + 1, ne3 = e3 + 1, ne5 = e5;
        sum = (sum + solve_dp(ne2, ne3, ne5)) % MOD;
    }
    long long res = (sum * inv5) % MOD;
    dp[e2][e3][e5] = res;
    return res;
}
 
// Helper: compute base^exp (with int128) for a given base.
int128 ipow128 (int base, int exp) {
    int128 ret = 1;
    for (int i=0; i<exp; i++) ret *= base;
    return ret;
}
 
// Main
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    unsigned long long N;
    cin >> N;
 
    // Factorize N by 2,3,5.
    unsigned long long temp = N;
    targetA = targetB = targetC = 0;
    while(temp % 2ULL == 0){
        targetA++;
        temp /= 2ULL;
    }
    while(temp % 3ULL == 0){
        targetB++;
        temp /= 3ULL;
    }
    while(temp % 5ULL == 0){
        targetC++;
        temp /= 5ULL;
    }
    // If there remains any other factor then N cannot be reached.
    if(temp != 1){
        cout << 0 << "\n";
        return 0;
    }
 
    // Our target product is 2^(targetA)*3^(targetB)*5^(targetC).
    targetVal = ipow128(2, targetA) * ipow128(3, targetB) * ipow128(5, targetC);
 
    // Determine safe bounds for our DP arrays.
    // A safe choice is to let the maximum index for 2 be floor(log2(N))+2, and similarly for 3 and 5.
    long double LN = logl((long double)N);
    max2Bound = (int)floor(LN / logl(2.0L)) + 2;
    max3Bound = (int)floor(LN / logl(3.0L)) + 2;
    max5Bound = (int)floor(LN / logl(5.0L)) + 2;
 
    // Precompute powers for 2,3,5 up to these bounds.
    p2.resize(max2Bound+1);
    p3.resize(max3Bound+1);
    p5.resize(max5Bound+1);
    p2[0] = 1; for (int i=1; i<=max2Bound; i++) p2[i] = p2[i-1] * 2;
    p3[0] = 1; for (int i=1; i<=max3Bound; i++) p3[i] = p3[i-1] * 3;
    p5[0] = 1; for (int i=1; i<=max5Bound; i++) p5[i] = p5[i-1] * 5;
 
    // Set up DP memo table.
    dp.assign(max2Bound+1, vector<vector<long long>>(max3Bound+1, vector<long long>(max5Bound+1, -1)));
 
    // Compute modular inverse of 5.
    inv5 = modexp(5, MOD-2, MOD);
 
    // Answer is the probability starting from state (0,0,0)
    long long ans = solve_dp(0,0,0);
    cout << ans % MOD << "\n";
    return 0;
}

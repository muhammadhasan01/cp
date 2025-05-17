#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned long long N;
    cin >> N;
    
    // Sieve primes up to 300000.
    int sieveLimit = 300000;
    vector<bool> isPrime(sieveLimit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= sieveLimit; i++){
        if(isPrime[i]){
            for (int j = i * i; j <= sieveLimit; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= sieveLimit; i++){
        if(isPrime[i])
            primes.push_back(i);
    }
    
    // Precompute prefix count array: prefix[i] is number of primes <= i.
    vector<int> prefix(sieveLimit + 1, 0);
    for (int i = 1; i <= sieveLimit; i++){
        prefix[i] = prefix[i - 1] + (isPrime[i] ? 1 : 0);
    }
    
    // Limit for a: a <= floor(N^(1/5))
    int limitA = 0;
    {
        long double root = pow((long double)N, 1.0L / 5.0L);
        limitA = floor(root);
    }
    
    unsigned long long ans = 0;
    // Loop over primes for a (only those a <= limitA)
    for (size_t i = 0; i < primes.size(); i++){
        int a = primes[i];
        if(a > limitA) break;
        unsigned long long a2 = (unsigned long long)a * a;
        
        // For each a, loop over candidate c (c > b, so start from i+2)
        for (size_t j = i + 2; j < primes.size(); j++){
            int c = primes[j];
            unsigned long long c2 = (unsigned long long)c * c;
            // If a^2 * c^2 > N then further (larger) c won't work.
            if(a2 * c2 > N) break;
            
            // From a^2 * b * c^2 <= N, we get b <= floor(N/(a^2*c^2)).
            unsigned long long M = N / (a2 * c2);
            // b must also be less than c; so let b_max = min(M, c - 1)
            unsigned long long b_max = min(M, (unsigned long long)c - 1);
            // Also b must be at least a+1.
            if(b_max < (unsigned long long)a + 1) continue;
            
            // Count primes b in [a+1, b_max] using our prefix array.
            ans += (unsigned long long)(prefix[b_max] - prefix[a]);
        }
    }
    
    cout << ans << "\n";
    return 0;
}

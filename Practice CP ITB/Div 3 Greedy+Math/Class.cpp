// C++ program to prlong long all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;
#define M  100000001

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n,k,c=0;
    cin >> n;
    bitset<M+2> prime;
    prime.set();
    prime[0] = 0;
    prime[1] = 0;
    for (long long p=2; p*p<=M; p++)
    {
        if (prime[p])
        {
            for (long long i=p*2; i<=M; i += p)
                prime[i] = 0;
        }
    }
    while(n--){
        cin >> k;
        while(!prime[k]){
            k--;
            c++;
        }
        cout << c << "\n";
        c = 0;
    }
    return 0;
}

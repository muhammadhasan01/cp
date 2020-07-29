#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    long long m = n / 2;
    long long d = max(0LL, m / (k + 1));
    cout << d << " " << k * d << " " << n - d * (k + 1) << '\n';
    
    return 0;
}
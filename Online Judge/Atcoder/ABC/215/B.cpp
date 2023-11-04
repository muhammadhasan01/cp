#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long n;
    cin >> n;
    int k = 0;
    int x = 0;
    long long cur = 1;
    while (cur <= n) {
        k = max(k, x);
        cur *= 2;
        x++;
    }
    cout << k << '\n';
    
    return 0;
}
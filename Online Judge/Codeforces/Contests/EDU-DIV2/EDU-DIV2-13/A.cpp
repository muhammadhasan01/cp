#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    if (n % k == 0) {
        cout << n + k << '\n';
    } else {
        cout << ((n + k - 1) / k) * k << '\n';
    }

    return 0;
}
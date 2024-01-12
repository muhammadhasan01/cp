#include <bits/stdc++.h>

using namespace std;

const long long FOUR[] = {1, 2, 4};
const long long FIVE[] = {1, 3, 5};

long long F(long long n, long long k) {
    if (n < 3 || k == 0) {
        return 0;
    }
    if (n % 3 == 0) {
        return (n / 3) * k;
    }
    if (n == 4) {
        --k;
        return (k / 3) * FOUR[2] + FOUR[k % 3];
    }
    if (n == 5) {
        --k;
        return (k / 3) * FIVE[2] + FIVE[k % 3];
    }
    long long three = ((n / 3) - 1) * 3;
    return F(three, k) + F(n - three, k);
}

void solve() {
    long long n, k;
    cin >> n >> k;
    cout << F(n, k) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}
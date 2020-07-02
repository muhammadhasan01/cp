#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    if (k <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    long long upp = (k - 1) / 2;
    if (n <= upp || (k % 2 == 0 && n <= upp + 1)) {
        cout << 0 << '\n';
        return 0;
    }
    long long l = 1, r = upp, down = upp;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (k - mid <= n) {
            r = mid - 1;
            down = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << upp - down + 1 << '\n';

    return 0;
}
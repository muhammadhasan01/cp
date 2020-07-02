#include <bits/stdc++.h>

using namespace std;

long long n, s;

long long get(long long x) {
    long long ret = x;
    while (x) {
        ret -= x % 10;
        x /= 10;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    long long l = 0, r = n, pos = n + 1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (get(mid) >= s) {
            r = mid - 1;
            pos = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << (n - pos + 1) << '\n';

    return 0;
}
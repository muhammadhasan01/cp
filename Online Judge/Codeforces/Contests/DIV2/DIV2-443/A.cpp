#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
long long s[N], d[N];

long long ceil(long long a, long long b) {
    return (a + b - 1) / b;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> d[i];
    }
    long long cur = s[1];
    for (int i = 2; i <= n; i++) {
        long long l = 0, r = 1e9;
        long long pos = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (s[i] + d[i] * mid > cur) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cur = s[i] + d[i] * pos;
    }
    cout << cur << '\n';

    return 0;
}
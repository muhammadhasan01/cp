#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long x;
    cin >> x;
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    long long div = x / sum;
    long long k = div * n;
    long long cur = sum * div;
    for (int i = 0; i < n; i++) {
        if (cur > x) {
            break;
        }
        cur += a[i];
        k++;
    }
    cout << k << '\n';
    
    return 0;
}
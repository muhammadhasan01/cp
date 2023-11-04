#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    long long b;
    cin >> n >> b;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum >= b) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    assert(false);
    
    return 0;
}
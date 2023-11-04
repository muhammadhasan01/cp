#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> zero(n);
    if (a == zero) {
        cout << 0 << "\n";
        return 0;
    }
    int ans = 1;
    for (int i = n / 2; i > 0; i /= 2) {
        vector<int> b(n);
        for (int j = 0; j < n; j++) {
            b[j] = a[j] ^ a[(i + j) % n];
        }
        if (b != zero) {
            a.swap(b);
            ans += i;
        }
    }
    cout << ans << "\n";
    
    return 0;
}


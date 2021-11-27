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
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mx) {
            cout << i + 1 << '\n';
            return 0;
        }
        mx = max(a[i] + 1, mx);
    }
    cout << -1 << '\n';
    
    return 0;
}
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
    int mx = *max_element(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            ++cnt;
        }
    }
    if (mx == a[0] && cnt == 1) {
        cout << 0 << '\n';
    } else {
        cout << mx - a[0] + 1 << '\n';
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, l;
    cin >> n >> l;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [&](auto& l, auto& r) {
        return l + r < r + l; 
    });
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << '\n';
    
    return 0;
}
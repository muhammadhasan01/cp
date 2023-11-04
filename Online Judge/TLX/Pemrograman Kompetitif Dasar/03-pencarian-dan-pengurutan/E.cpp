#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [&](auto& l, auto& r) {
        int x = l.length();
        int y = r.length();
        if (x == y) {
            return l < r;
        }
        return x < y;
    });
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    
    return 0;
}
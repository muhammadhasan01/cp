#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    int l = 0, e = 0, g = 0;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val < x) {
            l++;
        } else if (val == x) {
            e++;
        } else if (val > x) {
            g++;
        }
    }
    if (l + e < g) {
        cout << g - l - e << '\n'; 
    } else if (e + g <= l) {
        cout << l - e - g + 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    
    return 0;
}
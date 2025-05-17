#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int r, x;
    cin >> r >> x;
    if (x == 1) {
        cout << (1600 <= r && r <= 2999 ? "Yes" : "No") << '\n';
    } else if (x == 2) {
        cout << (1200 <= r && r <= 2399 ? "Yes" : "No") << '\n';
    }
    
    return 0;
}
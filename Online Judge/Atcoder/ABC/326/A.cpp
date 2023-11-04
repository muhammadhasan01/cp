#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x, y;
    cin >> x >> y;
    if (y >= x && y - x <= 2) {
        cout << "Yes" << '\n';
    } else if (x > y && x - y <= 3) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    
    return 0;
}
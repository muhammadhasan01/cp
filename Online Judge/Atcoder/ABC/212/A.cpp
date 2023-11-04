#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    if (0 < a && b == 0) {
        cout << "Gold" << '\n';
    } else if (a == 0 && b > 0) {
        cout << "Silver" << '\n';
    } else if (a > 0 && b > 0) {
        cout << "Alloy" << '\n';
    }
    
    return 0;
}
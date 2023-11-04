#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x;
    cin >> x;
    if (x > 0 && x % 100 == 0) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    if (1 <= n && n <= 125) {
        cout << 4 << '\n';
    } else if (126 <= n && n <= 211) {
        cout << 6 << '\n';
    } else if (212 <= n && n <= 214) {
        cout << 8 << '\n';
    }
    
    return 0;
}
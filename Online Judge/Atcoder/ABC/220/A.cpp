#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = a; i <= b; i++) {
        if (i % c == 0) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    
    return 0;
}
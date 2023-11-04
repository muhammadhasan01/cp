#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (n % c == 0) {
        cout << "YES" << '\n';
        return 0;
    }
    if (n % a == 0 && n % b != 0) {
        cout << "YES" << '\n';
        return 0;
    }
    cout << "NO" << '\n';
    
    return 0;
}
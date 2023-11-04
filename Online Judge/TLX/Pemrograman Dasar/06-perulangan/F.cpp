#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        if (n % i == 0) {
            cout << i << '\n';
        }
    }
    
    return 0;
}
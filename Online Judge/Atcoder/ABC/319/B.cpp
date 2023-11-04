#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        bool flag = false;
        for (int j = 1; j <= 9; j++) {
            if (n % j == 0 && i % (n / j) == 0) {
                cout << j;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "-";
        }
    }
    cout << '\n';
    
    return 0;
}
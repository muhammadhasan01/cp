#include <bits/stdc++.h>

using namespace std;

int n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    char CX = (n % 2 == 1 ? ' ' : '*');
    char CY = (n % 2 == 1 ? '&' : '#');
    for (int i = 1, cnt = n - 1; i <= n; i++, cnt--) {
        for (int j = 1; j <= n + i - 1; j++) {
            cout << (j <= cnt ? CX : CY);
        }
        cout << '\n';
    }

    return 0;
}
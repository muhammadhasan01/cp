#include <bits/stdc++.h>

using namespace std;

int b, w;
char x = '@', y = '.';

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);
    cin >> b >> w;
    if (b > w) {
        swap(b, w);
        swap(x, y);
    }
    if (b == w) {
        cout << 2 * b << " " << 1 << '\n';
        for (int i = 1; i <= 2 * b; i++) {
            cout << (i & 1 ? x : y) << '\n';
        }
        return 0;
    }
    cout << 2 * (b - 1) + 3 * (w - b + 1) << " " << 2 << '\n';
    for (int i = 1; i <= 2 * (b - 1); i++) {
        char cur = (i & 1 ? x : y);
        for (int j = 1; j <= 2; j++) cout << cur;
        cout << '\n';
    }
    for (int i = 1; i <= w - b + 1; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == 2) {
                cout << y << x << '\n';
            } else {
                cout << x << x << '\n';
            }
        }
    }

    return 0;
}
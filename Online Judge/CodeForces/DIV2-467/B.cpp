#include<bits/stdc++.h>
using namespace std;

int p, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> y;
        do {
        bool ok = true;
        for (int i = 1; i * i <= y; i++) {
            if (y % i == 0) {
                if (i != 1 && i <= p) {
                    ok = false;
                    break;
                }
                if (y / i > 1 && y / i <= p) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            cout << y << "\n";
            return 0;
        }
        y--;
    } while(y > p);
    cout << -1 << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int tc;
int x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> x >> y;
        if (x == 1) {
            cout << (x >= y ? "YES" : "NO") << '\n';
        } else if (x == 2 || x == 3) {
            cout << (3 >= y ? "YES" : "NO") << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }


    return 0;
}

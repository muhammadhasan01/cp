#include <bits/stdc++.h>
using namespace std;

int n;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) & 1) {
                cout << "B";
            } else {
                cout << "W";
            }
            if (j == n) cout << '\n';
        }
    }


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int tc;
int n, m;


int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        } else if (n == 2) {
            cout << m << '\n';
            continue;
        } else {
            cout << 2 * m << '\n';
        }
    }

    return 0;
}
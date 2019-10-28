#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cout << n - x + 1 << (i == n ? '\n' : ' ');
    }

    return 0;
}

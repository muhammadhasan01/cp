#include <bits/stdc++.h>

using namespace std;

int n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        res += (x == 0);
    }
    if (n == 1) {
        cout << (res == 0 ? "YES" : "NO") << '\n';
        return 0;
    }
    cout << (res == 1 ? "YES" : "NO") << '\n';

    return 0;
}
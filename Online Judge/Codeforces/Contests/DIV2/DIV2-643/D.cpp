#include <bits/stdc++.h>

using namespace std;

int n, s;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    int dif = s - n + 1;
    for (int k = 1; k < s; k++) {
        int y = s - k;
        if (k <= n - 1 || y <= n - 1) continue;
        if (k >= dif || y >= dif) continue;
        cout << "YES" << '\n';
        for (int i = 1; i < n; i++) cout << 1 << ' ';
        cout << dif << '\n';
        cout << k << '\n';
        return 0;
    }
    cout << "NO" << '\n';

    return 0;
}
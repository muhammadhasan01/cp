#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, x, y;
        cin >> n >> x >> y;
        int black = (n + 1) / 2;
        int white = n - black;
        cout << (black <= x && white <= y ? "YES" : "NO") << '\n';
    }

    return 0;
}
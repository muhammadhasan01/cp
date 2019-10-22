#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int tc;
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        long long odd = 0, even = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x & 1) odd++;
            else even++;
        }
        cin >> m;
        long long odx = 0, evenx = 0;
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            if (x & 1) odx++;
            else evenx++;
        }
        cout << odd * odx + even * evenx << '\n';
    }

    return 0;
}

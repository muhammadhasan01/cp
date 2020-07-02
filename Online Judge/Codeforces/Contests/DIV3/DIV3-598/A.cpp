#include <bits/stdc++.h>

using namespace std;

int q;
int a, b, n, s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> a >> b >> n >> s;
        int ns = max(0, (s - b));
        int fl = (ns + n - 1) / n;
        if (fl > a) {
            cout << "NO" << '\n';
        } else if (ns == 0) {
            cout << "YES" << '\n';
        } else {
            cout << (n * fl - ns <= b ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}

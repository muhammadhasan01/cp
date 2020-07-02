#include <bits/stdc++.h>
using namespace std;

int t;
long long s, i, e;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> s >> i >> e;
        s += e;
        if (s <= i) {
            cout << 0 << '\n';
        } else {
            cout << min(e + 1, (s - i + 1) / 2) << '\n';
        }
    }


    return 0;
}

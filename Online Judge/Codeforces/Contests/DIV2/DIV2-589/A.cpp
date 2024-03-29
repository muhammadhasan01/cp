#include <bits/stdc++.h>
using namespace std;

int l, r;

bool check(int x) {
    set<int> s;
    while (x > 0) {
        int k = x % 10;
        if (s.find(k) == s.end()) {
            s.insert(k);
        } else {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (check(i)) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}

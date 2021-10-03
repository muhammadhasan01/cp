#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    auto query = [&](int q) -> int {
        cout << "? " << q + 1 << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    int B = sqrt(n) - 1;
    for (int i = 0; i < B; i++) {
        query(i);
    }
    int x = 0;
    int v = query(x);
    while (v == k) {
        x = (x + B) % n;
        v = query(x);
    }
    if (v < k) {
        while (query((x + B) % n) < k) {
            x = (x + B) % n;
        }
        while (query((x + 1) % n) < k) {
            x = (x + 1) % n;
        }
        x = (x + 1) % n;
    } else {
        while (query((x - B + n) % n) > k) {
            x = (x - B + n) % n;
        }
        while (query((x - 1 + n) % n) > k) {
            x = (x - 1 + n) % n;
        }
        x = (x - 1 + n) % n;
    }
    cout << "! " << x + 1 << endl;

    return 0;
}
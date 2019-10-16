#include <bits/stdc++.h>
using namespace std;

const int N = 30 + 5;
int m, n;
bitset<N> a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cout << 1 << endl;
        int x;
        cin >> x;
        if (x == 0 || x == -2) {
            exit(0);
        } else if (x == 1) {
            a[i] = 1;
        }
    }
    int l = 1, r = m;
    for (int it = 1; it <= 30; it++) {
        int mid = (l + r) >> 1;
        int x;
        cout << mid << endl;
        cin >> x;
        int i = (it % n == 0 ? n : it % n);
        if (a[i] == 0) x = -x;
        if (x == 0 || x == -2) exit(0);
        if (x == 1) {
            l = mid + 1;
        } else if (x == -1) {
            r = mid - 1;
        }
    }

    return 0;
}

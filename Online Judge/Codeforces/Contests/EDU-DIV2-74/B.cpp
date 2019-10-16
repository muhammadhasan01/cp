#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int q;
int n, r;
int x[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n >> r;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        sort(x + 1, x + 1 + n, greater<int>());
        int c = 0, last;
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                c++;
                last = x[i];
            } else if (x[i] != last) {
                last = x[i];
                if (x[i] - c * r > 0) {
                    c++;
                } else {
                    break;
                }
            }
        }
        cout << c << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 35;

int tc;
int n, k;
int a[N], b[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (k) {
                for (int j = n; j >= 1; j--) {
                    if (b[j] > a[i]) {
                        swap(a[i], b[j]);
                        --k;
                        break;
                    }
                }
            }
            sum += a[i];
        }
        cout << sum << '\n';
    }

    return 0;
}
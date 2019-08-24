#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') c1++;
        if (b[i] == '1') c2++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1' && b[i] == '0') {
            if (i + 1 < n && a[i + 1] == '0' && b[i + 1] == '1') {
                swap(a[i], a[i + 1]);
                ans++;
            }
        } else if (a[i] == '0' && b[i] == '1') {
            if (i + 1 < n && a[i + 1] == '1' && b[i + 1] == '0') {
                swap(a[i], a[i + 1]);
                ans++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) ans++;
    }
    cout << ans << '\n';

    return 0;
}

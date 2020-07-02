#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, w;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < w; i++) {
        cin >> b[i];
    }
    if (w == 1) {
        cout << n << '\n';
        return 0;
    } else if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1] - a[i];
    }
    for (int i = 0; i < w - 1; i++) {
        b[i] = b[i + 1] - b[i];
    }
    n--, w--;
    vector<int> lps(w + 1, 0);
    for (int i = 1, j = 0; i < w; i++) {
        j = lps[i - 1];
        while (j > 0 && b[i] != b[j]) j = lps[j - 1];
        if (b[j] == b[i]) j++;
        lps[i] = j;
    }
    int i = 0, j = 0, ans = 0;
    while (i < n) {
        if (a[i] == b[j]) {
            i++, j++;
        }
        if (j == w) {
            ans++;
            j = lps[j - 1];
        } else if (i < n && a[i] != b[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}

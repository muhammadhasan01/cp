#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
int p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    if (is_sorted(p + 1, p + 1 + n)) {
        cout << "YES" << '\n';
        return 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            swap(p[i], p[j]);
            if (is_sorted(p + 1, p + 1 + n)) {
                cout << "YES" << '\n';
                return 0;
            }
            swap(p[i], p[j]);
        }
    }
    cout << "NO" << '\n';

    return 0;
}
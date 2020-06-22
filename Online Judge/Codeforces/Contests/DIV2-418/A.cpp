#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n, k;
int a[N], b[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    if (k == 1) {
        for (int i = 1; i <= n; i++) if (a[i] == 0) a[i] = b[1];
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (a[i] >= a[i + 1]) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
        return 0;
    }
    cout << "Yes" << '\n';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m;
int a[N][5];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int cur = 1;
    for (int i = n; i >= 1; i--) {
        if (cur > m) break;
        a[n - i + 1][1] = cur++;
        if (cur > m) break;
        a[n - i + 1][4] = cur++;
    }
    for (int i = n; i >= 1; i--) {
        if (cur > m) break;
        a[n - i + 1][2] = cur++;
        if (cur > m) break;
        a[n - i + 1][3] = cur++;
    }
    for (int i = n; i >= 1; i--) {
        if (a[n - i + 1][2])
            cout << a[n - i + 1][2] << ' ';
        if (a[n - i + 1][1])
            cout << a[n - i + 1][1] << ' ';
        if (a[n - i + 1][3])
            cout << a[n - i + 1][3] << ' ';
        if (a[n - i + 1][4])
            cout << a[n - i + 1][4] << ' ';
    }
    cout << '\n';

    return 0;
}
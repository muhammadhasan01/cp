#include <bits/stdc++.h>
using namespace std;

int a[10];
int b[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 6; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 3; i <= 5; i += 2) {
        if (a[i] <= a[1] && b[i] <= b[1] && a[i + 1] >= a[2] && b[i + 1] >= b[2]) {
            puts("NO");
            return 0;
        }
    }
    int x = 5, y = 3;
    for (int t = 1; t <= 2; t++) {
        swap(x, y);
        if (a[x] <= a[1] && b[x] <= b[1] && a[x + 1] >= a[1] && b[x + 1] >= b[2]
        && a[x + 1] >= a[y] && b[y] <= b[1] && b[y + 1] >= b[2] && a[y + 1] >= a[2]) {
            puts("NO");
            return 0;
        }
    }
    for (int t = 1; t <= 2; t++) {
        swap(x, y);
        if (a[x] <= a[1] && b[x] <= b[2] && a[x + 1] >= a[2] && b[x + 1] >= b[2]
        && b[x] <= b[y + 1] && b[y] <= b[1] && a[y] <= a[1] && a[y + 1] >= a[2]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");

    return 0;
}

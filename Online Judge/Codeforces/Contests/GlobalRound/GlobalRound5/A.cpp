#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int a[N], c[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            c[i] = 1;
            a[i] = (a[i] - 1) / 2;
        } else {
            a[i] /= 2;
        }
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1 && sum < 0) {
            a[i]++;
            sum++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << '\n';
    }


    return 0;
}

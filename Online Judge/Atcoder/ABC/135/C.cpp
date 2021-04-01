#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n + 1; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    long long sum = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (i > 1) {
            int mini = min(a[i], b[i - 1]);
            sum += mini;
            a[i] -= mini, b[i - 1] -= mini;
        }
        int mini = min(a[i], b[i]);
        sum += mini;
        a[i] -= mini, b[i] -= mini;
    }
    cout << sum << '\n';

    return 0;
}
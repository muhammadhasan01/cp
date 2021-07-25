#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
char a[N];
bool is_a[N][2];
int pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 'b') {
            continue;
        }
        if (a[i] == 'a') {
            is_a[i][0] = 1;
        }
        if (is_a[i - 1][0]) {
            is_a[i][0] = true;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] == 'b') {
            continue;
        }
        if (a[i] == 'a') {
            is_a[i][1] = 1;
        }
        if (is_a[i + 1][1]) {
            is_a[i][1] = true;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (is_a[i][0] || is_a[i][1]) {
            pre[i]++;
        }
        ans = max(ans, pre[i]);
    }
    cout << ans << '\n';

    return 0;
}
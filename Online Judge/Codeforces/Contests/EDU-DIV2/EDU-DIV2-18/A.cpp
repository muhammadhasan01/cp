#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 2e9 + 100;

int n;
int a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = INF;
    for (int i = 1; i < n; i++) {
        ans = min(ans, abs(a[i] - a[i + 1]));
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i + 1]) == ans) {
            ++cnt;
        }
    }
    cout << ans << " " << cnt << '\n';

    return 0;
}
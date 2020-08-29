#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

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
    int ans = 1;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            ++cur;
        } else {
            cur = 1;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}
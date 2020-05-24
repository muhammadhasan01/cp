#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
pair<int, int> a[N];
int ans[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i].first = (x - (n - i));
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n, greater<pair<int, int>>());
    for (int i = 1; i <= n; i++) {
        ans[n - i + 1] = a[i].first + i - 1;
        if (i > 1 && a[i].first == a[i - 1].first) {
            cout << ":(" << '\n';
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
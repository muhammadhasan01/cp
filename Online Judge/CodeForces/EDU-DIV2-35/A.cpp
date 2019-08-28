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
    int minss = 1e9 + 5;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        minss = min(minss, a[i]);
    }
    vector<int> pl;
    for (int i = 1; i <= n; i++) {
        if (a[i] == minss) {
            pl.push_back(i);
        }
    }

    int ans = 1e9;
    for (int i = 0; i < pl.size() - 1; i++) {
        ans = min(ans, pl[i + 1] - pl[i]);
    }
    cout << ans << '\n';

    return 0;
}

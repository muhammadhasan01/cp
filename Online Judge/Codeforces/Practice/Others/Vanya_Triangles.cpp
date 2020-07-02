#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n;
pair<short int, short int> p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    if (n < 3) {
        puts("0");
        return 0;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if ((p[j].second - p[i].second) * (p[k].first - p[j].first) == (p[k].second - p[j].second) * (p[j].first - p[i].first)) continue;
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

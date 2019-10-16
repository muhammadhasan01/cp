#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
pair<int,int> p[N];

bool cmpr(pair<int,int> a, pair<int,int> b) {
    return (a.first + a.second < b.first + b.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p + 1, p + 1 + n, cmpr);
    int last = 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (p[i].first - p[i].second >= p[last].first + p[last].second) {
            last = i;
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}

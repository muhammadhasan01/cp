#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e2 + 5;

int n, w;
pair<int,int> a[N];
int ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n, greater<pair<int,int>>());

    int cur = w;
    for (int i = 1; i <= n; i++) {
        int need = (a[i].first % 2 != 0) + a[i].first / 2;
        cur -= need;
        ans[a[i].second] =need;
    }
    int i = 1;
    while (cur>0) {
        while (cur>0 && ans[a[i].second] < a[i].first) {
            ans[a[i].second]++;
            cur--;
        }
        i++;
    }
    if (cur < 0) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
}

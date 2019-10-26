#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
vector<int> v[N];
int cnt[205];
int k[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int val; cin >> val;
        sum += val;
        v[k[i]].push_back(val);
    }

    int ans = 1e9;
    for (int i = 1; i <= N - 5; i++) {
        if ((int) v[i].size() > 0) {
            int res = 0;
            for (auto e : v[i]) res += e;
            int need = (int) v[i].size() - 1;
            for (int j = 200; j >= 1; j--) {
                int k = cnt[j];
                if (need <= k) {
                    res += need * j;
                    need = 0;
                } else {
                    res += k * j;
                    need -= k;
                }

                if (need == 0) break;
            }
            ans = min(ans, sum - res);
            for (auto e : v[i]) cnt[e]++;
        }
    }

    cout << ans << '\n';

    return 0;
}

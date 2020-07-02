#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 2e8;

int n;
int x[N];
int mini, maxi;

void solve() {
    if (maxi - mini <= 1) {
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            cout << x[i] << (i == n ? '\n' : ' ');
        }
        return;
    }
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[x[i]]++;
    }
    int cnt_1 = mp[mini], cnt_2 = mp[mini + 1], cnt_3 = mp[maxi];
    int dif = abs(cnt_1 - cnt_3);
    int res = cnt_2 + dif;
    int rres = n - cnt_2 + (cnt_2 & 1);
    if (rres < res) {
        cout << rres << '\n';
        for (int i = 1; i <= cnt_1 + cnt_2 / 2; i++) {
            cout << mini << " ";
        }
        for (int i = 1; i <= cnt_3 + cnt_2 / 2; i++) {
            cout << maxi << " ";
        }
        if (cnt_2 & 1) cout << mini + 1 << '\n';
        return;
    }
    cout << res << '\n';
    if (cnt_1 == cnt_3) {
        ++mini;
        for (int i = 1; i <= n; i++) {
            cout << mini << (i == n ? '\n' : ' ');
        }
        return;
    }
    for (int i = 1; i <= n - dif; i++) {
        cout << (mini + 1) << ' ';
    }
    int num = mini;
    if (cnt_3 > cnt_1) num = maxi;
    for (int i = 1; i <= dif; i++) {
        cout << num << (i == dif ? '\n' : ' ');
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    mini = INF, maxi = -INF;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        mini = min(mini, x[i]);
        maxi = max(maxi, x[i]);
    }
    solve();

    return 0;
}
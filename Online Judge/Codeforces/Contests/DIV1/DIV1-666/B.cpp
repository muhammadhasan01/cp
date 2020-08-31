#include <bits/stdc++.h>

using namespace std;

const int N = 1e2;

int tc;
int n;
int cnt[N + 5];

void solve() {
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    while (1) {
        int cur = 0;
        int first_occ = -1, last_occ = -1;
        for (int it = N; it >= 1; it--) {
            if (cnt[it] == 0) continue;
            cur += cnt[it];
            if (first_occ == -1)
                first_occ = it;
            last_occ = it;
        }
        if (cur <= 1) {
            cout << (cur ? "T" : "HL") << '\n';
            return;
        }
        assert(first_occ != -1);
        cnt[first_occ]--;
        cnt[first_occ - 1]++;
        cnt[last_occ]--;
        cnt[last_occ - 1]++;
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}
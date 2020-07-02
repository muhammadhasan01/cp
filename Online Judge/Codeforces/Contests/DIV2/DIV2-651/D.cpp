#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;

int n, k;
int need;
int a[N];

bool check(int ff, int ss, int cnt) {
    if (cnt > need) return true;
    if (cnt == need && k & 1) return true;
    if (cnt == need - 1 && k & 1) {
        return (ff > 1 && ss < n);
    }
    if (cnt == need && k % 2 == 0) {
        return (ff > 1 || ss < n);
    }
    return false;
}

bool can(int x) {
    int ff = -1, ss = -1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x) {
            if (ff == -1) ff = i;
            ss = i;
            i++;
            ++cnt;
        }
    }
    if (check(ff, ss, cnt)) return true;
    ff = -1, ss = -1;
    cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] <= x) {
            if (ff == -1) ff = i;
            ss = i;
            i++;
            ++cnt;
        }
    }
    if (check(ff, ss, cnt)) return true;
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    need = (k + 1) / 2;
    int l = 1, r = INF, ans = INF;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
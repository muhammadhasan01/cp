#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, k;
int a[N], suf[N], pre[N];
long long ans;

void getAnswer() {
    long long res = 0;
    for (int i = 1; i < n; i++) {
        int pos = -1;
        long long cur = 0;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] >= a[i]) {
                pos = j;
                break;
            }
            cur += a[i] - a[j];
        }
        if (pos == -1) continue;
        res += cur;
        i = pos - 1;
    }
    for (int i = n; i >= 2; i--) {
        int pos = -1;
        long long cur = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (a[j] == a[i]) {
                i = j - 1;
                break;
            }
            if (a[j] > a[i]) {
                pos = j;
                break;
            }
            cur += a[i] - a[j];
        }
        if (pos == -1) continue;
        res += cur;
        i = pos + 1;
    }
    ans = max(ans, res);
}

void solve(int pos, int x) {
    if (pos == n) {
        a[pos] += x;
        getAnswer();
        a[pos] -= x;
        return;
    }
    for (int val = 0; val <= x; val++) {
        a[pos] += val;
        solve(pos + 1, x - val);
        a[pos] -= val;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    solve(1, k);
    cout << ans << '\n';

    return 0;
}
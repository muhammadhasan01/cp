#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 3;
int n;
char s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int ans = 1e9, cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (s[i] == '(') cnt++;
        else cnt--;
        ans = min(ans, cnt);
    }

    if (cnt != 0) {
        cout << 0 << '\n' << 1 << ' ' << 1 << '\n';
        return 0;
    }

    int l = 1, r = 1;
    int res = 0;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt == ans) res++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (s[i] == s[j]) continue;
            swap(s[i], s[j]);
            int mini = 1e9, cur = 0, ret = 0;
            for (int k = 1; k <= n; k++) {
                if (s[k] == '(') cur++;
                else cur--;
                mini = min(mini, cur);
            }
            cur = 0;
            for (int k = 1; k <= n; k++) {
                if (s[k] == '(') cur++;
                else cur--;
                if (cur == mini) ret++;
            }
            swap(s[i], s[j]);
            mini = -mini;
            if (ret > res) {
                res = ret;
                l = i, r = j;
            }
        }
    }
    cout << res << '\n';
    cout << l << " " << r << '\n';

    return 0;
}

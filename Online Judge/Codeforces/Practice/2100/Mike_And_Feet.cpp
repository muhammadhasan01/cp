#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int a[N], ans[N], le[N], ri[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            le[i] = s.top();
        } else {
            le[i] = 0;
        }
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            ri[i] = s.top();
        } else {
            ri[i] = n + 1;
        }
        s.push(i);
    }
    for (int i = 1; i <= n; i++) {
        int len = ri[i] - le[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}

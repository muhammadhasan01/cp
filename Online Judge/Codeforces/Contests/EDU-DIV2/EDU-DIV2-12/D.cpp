#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int M = 2e6 + 5;

int n;
int a[N];
bool not_prime[M];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < M; i++) {
        if (not_prime[i]) continue;
        for (int j = i + i; j < M; j += i)
            not_prime[j] = 1;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    vector<int> ans = {a[1]};
    bool ok = false;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int res = a[i] + a[j];
            if (not_prime[res]) continue;
            ans = {a[i], a[j]};
            ok = true;
            break;
        }
        if (ok) break;
    }
    if (a[1] == 1) {
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                res.emplace_back(a[i]);
            } else if (!not_prime[a[i] + 1]) {
                res.emplace_back(a[i]);
                break;
            }
        }
        if ((int) res.size() > (int) ans.size()) {
            ans = res;
        }
    }
    int len = ans.size();
    cout << len << "\n";
    for (int i = 0; i < len; i++) {
        cout << ans[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}
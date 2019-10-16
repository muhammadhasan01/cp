#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    map<int,int> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    bool ok = true;
    set<int> bs;
    for (auto e : m) {
        if (e.second > 1) {
            bs.insert(e.first);
            ok = false;
        }
    }

    if (ok) {
        puts("0");
        return 0;
    }

    int len = bs.size();
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        map<int,int> temp;
        set<int> tk = bs;
        for (int j = i; j <= n; j++) {
            int cur = ++temp[a[j]];
            if (cur >= m[a[j]] - 1) {
                if (!tk.empty() && tk.find(a[j]) != tk.end()) tk.erase(a[j]);
            }
            if (tk.empty()) {
                ans = min(ans, j - i + 1);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}

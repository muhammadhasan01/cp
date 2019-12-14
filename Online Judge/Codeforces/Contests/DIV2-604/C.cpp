#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
int tc;
int n;
int a[N];
int g, s, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        g = 0, s = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> v;
        v.push_back({0, 0});
        int cur = a[1], cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == cur) {
                cnt++;
            } else {
                v.push_back({cur, cnt});
                cur = a[i];
                cnt = 1;
            }
        }
        v.push_back({cur, cnt});
        int m = v.size();
        int pos = 0;
        int sum = 0;
        for (int i = 1; i <= m; i++) {
            sum += v[i].second;
            if (sum > n / 2) break;
            pos = i;
        }
        if (pos < 3) {
            cout << 0 << " " << 0 << " " << 0 << '\n';
            continue;
        }
        g = v[1].second;
        int npos = pos + 1;
        for (int i = 2; i <= pos; i++) {
            s += v[i].second;
            npos = i + 1;
            if (s > g) break;
        }
        for (int i = npos; i <= pos; i++) {
            b += v[i].second;
        }
        if (g == 0 || s == 0 || b == 0 || (s <= g) || (b <= g)) {
            cout << 0 << " " << 0 << " " << 0 << '\n';
        } else {
            cout << g << " " << s << " " << b << '\n';
        }
    }

    return 0;
}

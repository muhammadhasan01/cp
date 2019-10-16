#include <bits/stdc++.h>
using namespace std;

const int N = 7e3 + 5;
int n;
pair<long long, int> p[N];
pair<long long, int> c[N];
long long f[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].second;
    }
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    sort(p + 1, p + 1 + n);
    long long ans = 0;
    int i = 1, j = 1;
    vector<long long> v;
    while (i <= n) {
        long long cur = p[i].first;
        int cnt = 0;
        while (i <= n && p[i].first == cur) {
            c[j].first += (1LL) * p[i].second;
            i++;
            cnt++;
        }
        f[j] = cur;
        c[j].second = cnt;
        if (cnt > 1) {
            ans += c[j].first;
            v.push_back(cur);
        }
        j++;
    }
    j--;
    int len = v.size();
    for (int i = 1; i <= j; i++) {
        if (c[i].second > 1) continue;
        long long cur = f[i];
        int cnt = 0;
        for (auto e : v) {
            for (int b = 0; b <= 60; b++) {
                bool x = (cur & (1LL << b));
                bool y = (e & (1LL << b));
                if (x && !y) {
                    cnt++;
                    break;
                }
            }
        }
        if (cnt == len) continue;
        ans += c[i].first;
    }
    cout << ans << '\n';

    return 0;
}

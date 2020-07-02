#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
pair<char, string> p[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    int pos = n;
    vector<bool> ok(30);
    vector<int> bad(30);
    for (int i = 1; i < n; i++) {
        char op = p[i].first;
        if (op == '.' || op == '?') {
            for (auto& e : p[i].second) {
                int xx = e - 'a';
                ok[xx] = 1;
            }
        } else {
            vector<bool> cont(30);
            for (auto& e : p[i].second) {
                int xx = e - 'a';
                if (cont[xx] || ok[xx]) continue;
                ++bad[xx];
                cont[xx] = 1;
            }
        }
        int maks = 0;
        for (int i = 0; i < 26; i++) {
            if (ok[i]) continue;
            maks = max(maks, bad[i]);
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (ok[i]) continue;
            if (maks == bad[i]) ++res;
        }
        if (res == 1) {
            pos = i + 1;
            break;
        }
    }
    int ans = 0;
    for (int i = pos; i < n; i++) {
        if (p[i].first == '.') continue;
        ++ans;
    }
    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            int pos = i;
            for (int j = i + 1; j < n; j++) {
                if (s[j] != '?') {
                    break;
                }
                pos = j;
            }
            vector<char> cc = {'R', 'B'};
            vector<int> cost(2);
            for (int it = 0; it < 2; it++) {
                for (int j = i, k = 0; j <= min(n - 1, pos + 1); j++, k++) {
                    if (j <= pos) {
                        s[j] = cc[k & 1];
                    }
                    if (j > 0 && s[j] == s[j - 1]) {
                        cost[it]++;
                    }
                }
                swap(cc[0], cc[1]);
            }
            if (cost[0] > cost[1]) {
                swap(cc[0], cc[1]);
            }
            for (int j = i, k = 0; j <= pos; j++, k++) {
                s[j] = cc[k & 1];
            }
            i = pos;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}
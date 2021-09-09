#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int K = 2;

int pre[N][K];

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int n = s.length();
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = s[i] - '0';
    }
    long long ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> add(n);
        bool ok = true;
        long long cur = 1;
        for (int i = 0; i < n; i++) {
            bool b = mask & (1 << i);
            int x = v[i] - add[i];
            if (b) {
                if (i + 2 >= n) {
                    ok = false;
                    break;
                }
                if (x == -1) {
                    cur = (cur * pre[x + N][0]);
                } else {
                    cur = (cur * pre[x][1]);
                }
                add[i + 2] += 1;
            } else {
                if (x == -1) {
                    ok = false;
                    break;
                }
                cur = (cur * pre[x][0]);
            }
        }
        if (!ok) {
            continue;
        }
        ans += cur;
    }
    cout << ans - 2 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int res = i + j;
            if (res >= N) {
                pre[res % N][1]++;
            } else {
                pre[res][0]++;
            }
        }
    }
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int ten[N];

void solve() {
    int s, n;
    cin >> s >> n;
    vector<int> v;
    v.emplace_back(s);
    for (int it = 1; it < n; it++) {
        sort(v.begin(), v.end());
        int len = v.size();
        int res = 0;
        bool ok = false;
        for (int i = 0; i < len; i++) {
            if (v[i] == 1) {
                continue;
            }
            if (v[i] < 10) {
                ok = true;
                v[i]--;
                res = 1;
                break;
            }
            int x = v[i];
            int m = 1;
            int c = 0;
            while (x > 0) {
                int d = x % 10;
                x /= 10;
                m = 10 * m;
                c++;
                if (d == 0) {
                    continue;
                }
                if (d == 1) {
                    if (x == 0) {
                        continue;
                    }
                    ok = true;
                } else {
                    ok = true;
                }
                if (ok) {
                    if (x == 0) {
                        int val = v[i];
                        v[i] = (d - 1) * ten[c - 1];
                        res = val - v[i];
                    } else {
                        m /= 10;
                        v[i] -= d * m;
                        res = d * m;
                    }
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            v.emplace_back(res);
            continue;
        }
        for (int i = 0; i < len; i++) {
            if (v[i] == 1) {
                continue;
            }
            int x = v[i];
            v[i] = x - x / 10;
            res = x / 10;
            break;
        }
        v.emplace_back(res);
    }
    sort(v.begin(), v.end());
    int len = v.size();
    for (int i = 0; i < len; i++) {
        cout << v[i] << " \n"[i == len - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ten[0] = 1;
    for (int i = 1; i < N; i++) {
        ten[i] = ten[i - 1] * 10;
    }
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}
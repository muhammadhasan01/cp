#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m;
    cin >> m;
    vector<int> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    int n;
    cin >> n;
    int take = m / n;
    int rem = m % n;
    sort(s.begin(), s.end());
    vector<int> p(n);
    for (int i = n - rem; i < n; i++) {
        p[i] = 1;
    }
    do {
        vector<int> pos(n);
        for (int i = 0, x = take - 1; i < n; i++) {
            x += p[i];
            pos[i] = x;
            x += take;
        }
        bool valid = true;
        for (int i = 0; i + 1 < n; i++) {
            if (s[pos[i]] == s[pos[i] + 1]) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            continue;
        }
        for (int i = 0; i + 1 < n; i++) {
            cout << s[pos[i]] + 1 << " \n"[i == n - 2];
        }
        return 0;
    } while (next_permutation(p.begin(), p.end()));
    
    return 0;
}
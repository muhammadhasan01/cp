#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 2; i < N; i++) {
        if (p[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            p[j] = i;
        }
    }
    int n, m;
    cin >> n >> m;
    set<int> P;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x > 1) {
            int pp = p[x];
            while (x % pp == 0) {
                x /= pp;
            }
            P.emplace(pp);
        }
    }
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        bool flag = true;
        int x = i;
        while (x > 1) {
            int pp = p[x];
            while (x % pp == 0) {
                x /= pp;
            }
            if (P.count(pp)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans.emplace_back(i);
        }
    }
    cout << (int) ans.size() << '\n';
    for (int x : ans) {
        cout << x << '\n';
    }
    
    return 0;
}
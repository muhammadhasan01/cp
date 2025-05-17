#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long p, t;
    string s;
    cin >> p >> t;
    cin >> s;
    int n = s.size();
    long long k = (t - 1) / p;
    for (int i = 0; i < n; ) {
        if (s[i] == 'W') {
            ++i;
            continue;
        }
        int j = i;
        while (j < n && s[j] != 'W') ++j;
        vector<int> infected, healthy;
        for (int idx = i; idx < j; ++idx) {
            if (s[idx] == 'I') infected.push_back(idx - i);
            else if (s[idx] == 'H') healthy.push_back(idx - i);
        }
        if (!healthy.empty() && infected.empty()) {
            cout << "CURED\n";
            return 0;
        }
        int m = j - i;
        vector<int> dist(m, INF);
        for (int x : infected) {
            dist[x] = 0;
        }
        for (int u = 1; u < m; ++u) {
            dist[u] = min(dist[u], dist[u-1] + 1);
        }
        for (int u = m-2; u >= 0; --u) {
            dist[u] = min(dist[u], dist[u+1] + 1);
        }
        for (int x : healthy) {
            if (dist[x] > k) {
                cout << "CURED\n";
                return 0;
            }
        }
        i = j;
    }
    cout << "ALL INFECTED\n";
    
    return 0;
}
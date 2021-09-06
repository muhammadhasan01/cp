#include <bits/stdc++.h>

using namespace std;

const int K = 26;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<vector<int>> dist(K, vector<int>(K));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            int u = i, v = j;
            if (u > v) {
                swap(u, v);
            }
            dist[i][j] = min(v - u, u + K - v);
        }
    }
    string s;
    cin >> s;
    int cur = 0;
    int n = s.length();
    int ans = 0;
    for (char cc : s) {
        int num = cc - 'a';
        ans += dist[cur][num];
        cur = num;
    }
    cout << ans << '\n';
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int M = 32768;
const int K = 20;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<long long> dist(M, INF);
    dist[0] = 0;
    {
        int x = M / 2;
        int cur = 1;
        while (x % 2 == 0) {
            dist[x] = cur;
            x /= 2;
            cur++;
        }
    }
    for (int i = M - 1; i >= 0; i--) {
        int j = (i + 1) % M;
        dist[i] = min(dist[i], dist[j] + 1);
        int cur = i;
        for (int it = 1; it <= K; it++) {
            cur = (cur * 2) % M;
            dist[i] = min(dist[i], dist[cur] + it);
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << dist[x] << " \n"[i == n - 1];
    }

    return 0;
}
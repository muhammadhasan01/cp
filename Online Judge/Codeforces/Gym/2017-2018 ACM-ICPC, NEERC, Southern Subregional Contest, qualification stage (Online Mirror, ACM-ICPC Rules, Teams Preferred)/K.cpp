#include <bits/stdc++.h>

using namespace std;

const int N = 605;

int n, a, b, k, f;
int road[N][N];
int p[N][2];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> k >> f;
    map<string, int> mp;
    for (int i = 1; i <= n; i++) {
        for (int it = 0; it < 2; it++) {
            string s; cin >> s;
            if (mp.count(s)) {
                p[i][it] = mp[s];
            } else {
                p[i][it] = 1 + mp.size();
                mp[s] = p[i][it];
            }
        }
    }
    int lastTrip = -1;
    for (int i = 1; i <= n; i++) {
        int u = p[i][0], v = p[i][1];
        if (u > v) swap(u, v);
        road[u][v] += (lastTrip == p[i][0] ? b : a);
        lastTrip = p[i][1];
    }
    priority_queue<int> pq;
    int cost = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (road[i][j] == 0) continue;
            cost += road[i][j];
            pq.emplace(road[i][j]);
        }
    }
    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        if (k > 0 && f < temp) {
            cost += (f - temp); --k;
        } else {
            break;
        }
    }
    cout << cost << '\n';

    return 0;
}
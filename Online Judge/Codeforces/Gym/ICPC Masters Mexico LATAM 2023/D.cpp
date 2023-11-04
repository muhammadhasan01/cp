#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int r, c, k;
    cin >> r >> c >> k;
    map<int, int> freq;
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto [val, cnt] : freq) {
        pq.emplace(cnt, val);
    }
    int ans = 0;
    for (int it = 0; it < k; it++) {
        if (pq.empty()) {
            break;
        }
        auto [cnt, _] = pq.top();
        pq.pop();
        ans += cnt;
    }
    cout << ans << '\n';
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x); pq.push(x);
        ans += x - pq.top(); pq.pop();
    }
    cout << ans << '\n';

    return 0;
}
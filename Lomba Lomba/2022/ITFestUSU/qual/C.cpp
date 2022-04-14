#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    set<long long> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.emplace(a[i]);
    }
    sort(a.begin(), a.end());
    long long k;
    cin >> k;
    int idx = 0;
    while (!pq.empty()) {
        idx = idx + 1;
        long long u = *pq.begin();
        if (u == k) {
            break;
        }
        pq.erase(pq.begin());
        for (long long x : a) {
            if (x > k || x * u > k) {
                break;
            }
            pq.emplace(x * u);
        }
    }
    cout << idx << '\n';
    
    return 0;
}
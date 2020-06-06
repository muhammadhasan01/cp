#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;
const int INF = 1e5;

long long n;
long long k;
long long cnt[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    deque<int> v(n);
    for (int i = 1; i <= n; i++) {
        cin >> v[i - 1];
    }
    for (int it = 1; it <= INF; it++) {
        if (v[0] > v[1]) {
            if (++cnt[v[0]] == k) break;
            int cur = v[1];
            v.erase(v.begin() + 1);
            v.emplace_back(cur);
        } else {
            if (++cnt[v[1]] == k) break;
            int cur = v[0];
            v.pop_front();
            v.emplace_back(cur);
        }
    }
    int cur = 0, pos = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > cur) {
            pos = i;
        }
    }
    cout << pos << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc, n;

void solve() {
    cin >> n;
    deque<int> dq(n);
    for (auto& e : dq) cin >> e;
    int frontz = 1;
    while (!dq.empty() && dq.front() == frontz) {
        dq.pop_front();
        frontz++;
    }
    int backz = n;
    while (!dq.empty() && dq.back() == backz) {
        dq.pop_back();
        backz--;
    }
    if (dq.empty()) {
        cout << 0 << '\n';
        return;
    }
    int cnt = 0;
    for (auto& e : dq) {
        if (e == frontz) ++cnt;
        ++frontz;
    }
    cout << (cnt == 0 ? 1 : 2) << "\n";
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    while (tc--) solve();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
int ans[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        priority_queue<pair<int, int>> pq;
        int cur = 1;
        pq.push(make_pair(n, -1));
        set<int> st;
        st.insert(0);
        st.insert(n + 1);
        while (!pq.empty()) {
            pair<int, int> temp = pq.top();
            pq.pop();
            int sz = temp.first;
            int pos = -temp.second;
            int l = pos, r = pos + sz - 1;
            int at = (l + r) / 2;
            ans[at] = cur++;
            auto it = st.lower_bound(at);
            int upz = *it;
            it--;
            int lowz = *it;
            if (upz - at > 1) {
                pq.push({upz - at - 1, -(at + 1)});
            }
            if (at - lowz > 1) {
                pq.push({at - lowz - 1, -(lowz + 1)});
            }
            st.insert(at);
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
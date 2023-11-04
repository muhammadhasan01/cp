#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> lines(n);
    vector<tuple<int, int, int>> events;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = make_tuple(x1, y1, x2, y2);
        if (y1 == y2) {
            events.emplace_back(x1, 1, i);
            events.emplace_back(x2, 2, i);
        } else if (x1 == x2) {
            events.emplace_back(x1, 3, i);
        }
    }
    sort(events.begin(), events.end());
    ordered_set st;
    long long ans = 0;
    for (auto [x, t, pos] : events) {
        auto [x1, y1, x2, y2] = lines[pos];
        if (t == 1) {
            st.insert(y1);
        } else if (t == 2) {
            st.erase(y1);
        } else if (t == 3) {
            ans += st.order_of_key(y2 + 1) - st.order_of_key(y1);
        }
    }
    cout << ans << '\n';
    
    return 0;
}
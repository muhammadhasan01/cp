#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int tp, curspeed;
    cin >> tp >> curspeed;
    int speed;
    int overtake = 0;
    stack<int> st;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        cin >> tp;
        if (tp == 1) {
            cin >> curspeed;
        } else if (tp == 2) {
            ans += overtake;
            overtake = 0;
        } else if (tp == 3) {
            cin >> speed;
            st.emplace(speed);
        } else if (tp == 4) {
            overtake = 0;
        } else if (tp == 5) {
            while (!st.empty()) st.pop();
        } else if (tp == 6) {
            overtake++;
        }
        while (!st.empty()) {
            int cur = st.top();
            if (cur >= curspeed) break;
            ++ans;
            st.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}
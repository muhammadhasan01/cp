#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int g = __gcd(abs(dx), abs(dy));
            st.emplace(dx / g, dy / g);
        }
    }
    cout << (int) st.size() << '\n';
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> a(4);
    set<int> st;
    for (int i = 0; i < 4; i++) {
        char cc;
        cin >> cc;
        a[i] = cc - '0';
        st.emplace(a[i]);
    }
    if ((int) st.size() == 1) {
        cout << "Weak" << '\n';
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i < 4; i++) {
        int x = a[i - 1];
        int y = a[i];
        if (y == (x + 1) % 10) {
            ++cnt;
        }
    }
    if (cnt == 3) {
        cout << "Weak" << '\n';
        return 0;
    }
    cout << "Strong" << '\n';
    
    return 0;
}
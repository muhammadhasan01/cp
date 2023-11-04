#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> state;

    auto add = [&]() -> void {
        if (state.empty()) {
            state.emplace_back(1);
            return;
        }
        int x = state.back();
        if (x == 0) {
            state.emplace_back(0);
        } else {
            state.emplace_back(-1);
        }
    };

    auto remove = [&]() -> void {
        assert(!state.empty());
        int x = state.back();
        state.pop_back();
        if (state.empty()) {
            return;
        }
        if (x == 1) {
            state.back() = 1;
        }
    };

    auto check = [&](int num) -> bool {
        if (state.empty()) {
            return num == 1;
        }
        int x = state.back();
        if (x == 1 && num == 0) {
            return false;
        }
        if (x == 0 && num == 1) {
            return false;
        }
        state.back() = num;
        return true;
    };

    for (char cc : s) {
        if (cc == '+') {
            add();
        } else if (cc == '-') {
            remove();
        } else {
            int num = cc - '0';
            if (!check(num)) {
                cout << "NO" << '\n';
                return; 
            }
        }
    }
    cout << "YES" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}
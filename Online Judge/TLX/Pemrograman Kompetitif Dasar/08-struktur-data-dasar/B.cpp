#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    deque<int> dq;
    bool isReverted = false;
    while (q--) {
        string op;
        cin >> op;
        if (op == "add") {
            int x, y;
            cin >> x >> y;
            while (y--) {
                if (!isReverted) {
                    dq.emplace_back(x);
                } else {
                    dq.emplace_front(x);
                }
            }
            cout << (int) dq.size() << '\n';
        } else if (op == "rev") {
            isReverted = !isReverted;
        } else if (op == "del") {
            int x;
            cin >> x;
            if (!isReverted) {
                cout << dq.front() << '\n';
                while (x--) {
                    dq.pop_front();
                }
            } else {
                cout << dq.back() << '\n';
                while (x--) {
                    dq.pop_back();
                }
            }
        }
    }
    
    return 0;
}
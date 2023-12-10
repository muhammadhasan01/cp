#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    deque<int> dq;
    int sum = 0;
    bool isReverted = false;
    while (q--) {
        string op;
        cin >> op;
        if (op == "add") {
            int x, y;
            cin >> x >> y;
            while (y--) {
                if (!isReverted) {
                    dq.emplace_back(x - sum);
                } else {
                    dq.emplace_front(x - sum);
                }
            }
            cout << (int) dq.size() << '\n';
        } else if (op == "rev") {
            isReverted = !isReverted;
        } else if (op == "del") {
            int x;
            cin >> x;
            if (!isReverted) {
                cout << dq.back() + sum << '\n';
                while (x--) {
                    dq.pop_back();
                }
            } else {
                cout << dq.front() + sum << '\n';
                while (x--) {
                    dq.pop_front();
                }
            }
        } else if (op == "adx") {
            int x;
            cin >> x;
            sum += x;
        } else if (op == "dex") {
            int x;
            cin >> x;
            sum -= x;
        }
    }
    
    return 0;
}
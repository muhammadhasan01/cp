#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    deque<int> dq;
    while (q--) {
        string s;
        cin >> s;
        if (s == "push_back") {
            int x;
            cin >> x;
            dq.emplace_back(x);
        } else if (s == "push_front") {
            int x;
            cin >> x;
            dq.emplace_front(x);
        } else if (s == "pop_back") {
            dq.pop_back();
        } else if (s == "pop_front") {
            dq.pop_front();
        }
    }
    for (int x : dq) {
        cout << x << '\n';
    }
    
    return 0;
}
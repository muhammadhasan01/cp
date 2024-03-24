#include <bits/stdc++.h>

using namespace std;

const int P = 2;

void solve() {
    int h, w;
    vector<int> x(P), y(P);
    cin >> h >> w;
    for (int i = 0; i < P; i++) {
        cin >> x[i] >> y[i];
    }
    string winner = "";
    if (abs(x[0] - x[1]) & 1) {
        winner = "Alice";
    } else {
        winner = "Bob";
    }
    if (x[0] > x[1]) {
        cout << "Draw" << '\n';
        return;
    }
    int dir = 0;
    if (y[0] == y[1]) {
        cout << winner << '\n';
        return;
    } else if (y[0] < y[1]) {
        dir = winner == "Alice" ? 1 : -1;
    } else if (y[0] > y[1]) {
        dir = winner == "Alice" ? -1 : 1;
    }
    int turn = 1;
    while (1) {
        if (x[0] == x[1] && y[0] == y[1]) {
            cout << winner << '\n';
            return;
        }
        if (turn) {
            x[0] += 1;
            y[0] = max(1, min(w, y[0] + dir));
        } else {
            x[1] -= 1;
            y[1] = max(1, min(w, y[1] + dir));
        }
        if (x[0] > h || x[1] < 0) {
            cout << "Draw" << '\n';
            return;
        }
        turn ^= 1;
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> F(n + 1, -1), B(n + 1, -1);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, y;
            cin >> x >> y;
            F[x] = y;
            B[y] = x;
        } else if (tp == 2) {
            int x, y;
            cin >> x >> y;
            F[x] = -1;
            B[y] = -1;
        } else {
            int x;
            cin >> x;
            deque<int> dq = {x};
            int bx = x;
            while (B[bx] != -1) {
                dq.emplace_front(B[bx]);
                bx = B[bx];
            }
            int fx = x;
            while (F[fx] != -1) {
                dq.emplace_back(F[fx]);
                fx = F[fx];
            }
            int m = (int) dq.size();
            cout << m << ' ';
            for (int i = 0; i < m; i++) {
                cout << dq[i] << " \n"[i == m - 1];
            }
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k;
map<int,int> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (vis[x] == 0) vis[x] = 1;
        else continue;
        dq.push_front(x);
        if ((int) dq.size() == k + 1) {
            vis[dq.back()] = 0;
            dq.pop_back();
        }
    }
    cout << dq.size() << '\n';
    for (auto e : dq) cout << e << " ";

    return 0;
}

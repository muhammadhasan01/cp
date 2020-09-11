#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n;
int ans[N];
int query;
bool vis[N];

void ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int one; cin >> one;
    cout << "? " << y << " " << x << endl;
    int two; cin >> two;
    if (one > two) {
        ans[x] = one;
    } else {
        ans[y] = two;
    }
    vis[max(one, two)] = 1;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1) {
        cout << "! " << 1 << endl;
        return 0;
    }
    for (int it = 1; it <= 100; it++) {
        int last = -1, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 0) {
                ++cnt;
                if (last != -1) {
                    ask(last, i);
                    last = -1;
                } else {
                    last = i;
                }
            }
        }
        if (cnt <= 1) break;
    }
    int last = -1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        last = i;
    }
    if (last != -1) {
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 0) {
                ans[i] = last;
                break;
            }
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i == n)
            cout << endl;
        else
            cout << " ";
    }

    return 0;
}
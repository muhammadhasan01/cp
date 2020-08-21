#include <bits/stdc++.h>

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e3 + 5;

int n;
int ans[N];

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    char CC; cin >> CC;
    if (CC == '>') return 1;
    else if (CC == '<') return -1;
    return 0;
}

void solve(vector<int> a, vector<int> b) {
    int len = a.size();
    if (len == 0) return;
    if (len == 1) {
        ans[a[0]] = b[0];
        return;
    }
    int x = a[rng32() % len];
    vector<int> l, r;
    int same = -1;
    for (int y : b) {
        int res = ask(x, y);
        if (res < 0)
            l.emplace_back(y);
        else if (res > 0)
            r.emplace_back(y);
        else
            same = y;
    }
    assert(same != -1);
    ans[x] = same;
    vector<int> lp, rp;
    for (int y : a) {
        if (y == x) continue;
        int res = ask(y, same);
        if (res > 0)
            lp.emplace_back(y);
        else if (res < 0)
            rp.emplace_back(y);
    }
    solve(l, lp);
    solve(r, rp);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    solve(a, a);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
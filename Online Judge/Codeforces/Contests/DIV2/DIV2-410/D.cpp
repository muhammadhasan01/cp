#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct st {
    int x, y, idx;
};

int n;
st p[N];
long long suf[N];

bool C(const st& a, const st& b) {
    if (a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x; p[i].idx = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].y;
    }
    sort(p + 1, p + 1 + n, C);
    int len = n / 2 + 1;
    cout << len << '\n';
    cout << p[1].idx;
    if (n % 2 == 0) cout << ' ' << p[2].idx << '\n';
    for (int i = n; i >= 3; i -= 2) {
        cout << ' ' << (p[i].y > p[i - 1].y ? p[i].idx : p[i - 1].idx);
    }
    cout << '\n';

    return 0;
}
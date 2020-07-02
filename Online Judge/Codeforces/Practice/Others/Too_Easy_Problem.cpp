#include <bits/stdc++.h>
using namespace std;

struct st {
    int l, r, idx;
};

const int N = 2e5 + 5;
int n, T;
st p[N];

bool cmpr(st a, st b) {
    if (a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].l >> p[i].r;
        p[i].idx = i;
    }

    sort(p + 1, p + 1 + n, cmpr);

    priority_queue<pair<int,int>> pq;
    int sum = 0;
    for (int i = n, j = n; i >= 1; i--) {
        while (p[j].l >= i && j >= 1) {
            sum += p[j].r;
            pq.push({p[j].r, p[j].idx});
            j--;
        }


        if ((int) pq.size() < i) continue;

        while ((int) pq.size() > i) {
            sum -= pq.top().first;
            pq.pop();
        }
        if (sum > T) continue;
        cout << i << '\n';
        cout << i << '\n';
        while (!pq.empty()) {
            cout << pq.top().second << ' ';
            pq.pop();
        }
        return 0;
    }

    cout << 0 << '\n' << 0 << '\n';

    return 0;
}

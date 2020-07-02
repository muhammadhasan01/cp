#include <bits/stdc++.h>
using namespace std;

struct st{
    int x, y, z, idx;
};

const int N = 5e4 + 5;
int n;
st p[N];
pair<int,int> ans[N];
int removed[N];

bool cmpr(st a, st b) {
    if (a.x == b.x) {
        if (a.y == b.y) {
            return a.z < b.z;
        }
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].idx = i;
    }
    sort(p + 1, p + 1 + n, cmpr);
    int k = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (p[i].x == p[i + 1].x && p[i].y == p[i + 1].y) {
            ans[++k] = {p[i].idx, p[i + 1].idx};
            removed[i] = removed[i + 1] = 1;
            i++;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        if (removed[i]) continue;
        int j = i + 1;
        while (removed[j]) j++;
        if (j <= n && p[i].x == p[j].x) {
            ans[++k] = {p[i].idx, p[j].idx};
            removed[i] = removed[j] = 1;
            i = j;
        } else if (j <= n) {
            i = j - 1;
        } else {
            break;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        if (removed[i]) continue;
        int j = i + 1;
        while (removed[j]) j++;
        if (j <= n) {
            ans[++k] = {p[i].idx, p[j].idx};
            removed[i] = removed[j] = 1;
            i = j;
        } else {
            break;
        }
    }
    for (int i = 1; i <= n / 2; i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }

    return 0;
}

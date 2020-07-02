#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct book {
    int t, a, b;
};

int n, k;
book p[N];
vector<int> v[3];

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int cnt_a = 0, cnt_b = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].t >> p[i].a >> p[i].b;
        if (p[i].a && p[i].b) {
            cnt_a++, cnt_b++;
            v[2].emplace_back(p[i].t);
        } else if (p[i].a) {
            cnt_a++;
            v[0].emplace_back(p[i].t);
        } else if (p[i].b) {
            cnt_b++;
            v[1].emplace_back(p[i].t);
        } else {
            continue;
        }
        res += p[i].t;
    }
    if (cnt_a < k || cnt_b < k) dismiss();
    for (int i = 0; i < 3; i++) sort(v[i].begin(), v[i].end());
    while (cnt_a > k && cnt_b > k) {
        if (!v[0].empty() && !v[1].empty()) {
            int cur = v[0].back() + v[1].back();
            int cur_2 = (v[2].empty() ? -1 : v[2].back());
            if (cur_2 >= cur) {
                res -= cur_2;
                v[2].pop_back();
            } else {
                if (v[0].back() >= v[1].back()) {
                    res -= v[0].back();
                    v[0].pop_back();
                    cnt_a--;
                } else {
                    res -= v[1].back();
                    v[1].pop_back();
                    cnt_b--;
                }
            }
        } else {
            if (v[2].empty()) break;
            res -= v[2].back();
            v[2].pop_back();
        }
        cnt_a--, cnt_b--;
    }
    while (cnt_a > k) {
        if (v[0].empty()) break;
        res -= v[0].back();
        v[0].pop_back();
        cnt_a--;
    }
    while (cnt_b > k) {
        if (v[1].empty()) break;
        res -= v[1].back();
        v[1].pop_back();
        cnt_b--;
    }
    cout << res << '\n';

    return 0;
}
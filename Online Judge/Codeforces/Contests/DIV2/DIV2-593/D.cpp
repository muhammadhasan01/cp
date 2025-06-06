#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5;
long long n, m, k;
set<long long> s1[N], s2[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        long long x, y;
        cin >> x >> y;
        s1[x].insert(y);
        s2[y].insert(x);
    }
    long long ci = 1, cj = 1;
    long long bl = 1, br = m, bu = 1, bd = n;
    long long cur = 1;
    short int d = 1;
    do {
        if (d == 1) {
            if (s1[ci].empty()) {
                cur += (br - cj);
                cj = br;
            } else {
                auto it = s1[ci].lower_bound(cj);
                if (it != s1[ci].end() && *it - 1 <= br) {
                    cur += (*it - cj - 1);
                    cj = *it - 1;
                    br = cj;
                } else {
                    cur += (br - cj);
                    cj = br;
                }
            }
            bu++;
        } else if (d == 2) {
            if (s2[cj].empty()) {
                cur += (bd - ci);
                ci = bd;
            } else {
                auto it = s2[cj].lower_bound(ci);
                if (it != s2[cj].end() && *it - 1 <= bd) {
                    cur += (*it - ci - 1);
                    ci = *it - 1;
                    bd = ci;
                } else {
                    cur += (bd - ci);
                    ci = bd;
                }
            }
            br--;
        } else if (d == 3) {
            if (s1[ci].empty()) {
                cur += (cj - bl);
                cj = bl;
            } else {
                auto it = s1[ci].lower_bound(cj);
                if (it != s1[ci].begin() && *(--it) >= bl) {
                    cur += (cj - *it - 1);
                    cj = *it + 1;
                    bl = cj;
                } else {
                    cur += (cj - bl);
                    cj = bl;
                }
            }
            bd--;
        } else if (d == 4) {
            if (s2[cj].empty()) {
                cur += (ci - bu);
                ci = bu;
            } else {
                auto it = s2[cj].lower_bound(ci);
                if (it != s2[cj].begin() && *(--it) >= bu) {
                    cur += (ci - *it - 1);
                    ci = *it + 1;
                    bu = ci;
                } else {
                    cur += (ci - bu);
                    ci = bu;
                }
            }
            bl++;
        }
        d++;
        if (d > 4) d = 1;
        if (bl > br) break;
        if (bu > bd) break;
    } while (1);

    long long need = n * m - k;

    puts(cur == need ? "Yes" : "No");

    return 0;
}

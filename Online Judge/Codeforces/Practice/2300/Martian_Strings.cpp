#include <bits/stdc++.h>

using namespace std;

const int B = 2;
const int K = 17;
const int NMAX = (1 << K);

int n, m;
int tc, ans;
string s[B], t[B];
vector<int> p[B];
int pre[NMAX];
int sp[NMAX][K][B];

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int getRange(int l, int r, int tp) {
    int k = pre[r - l + 1];
    return min(sp[l][k][tp], sp[r - (1 << k) + 1][k][tp]);
}

bool can(int x, int pos, int tp, bool lft) {
    if (p[tp][x] + pos >= n) return false;
    if (lft) {
        return (s[tp][p[tp][x] + pos] >= t[tp][pos]);
    } else {
        return (s[tp][p[tp][x] + pos] <= t[tp][pos]);
    }
}

bool check(int x, int pos, int tp) {
    if (x == -1) return false;
    if (p[tp][x] + pos >= n) return false;
    return (s[tp][p[tp][x] + pos] == t[tp][pos]);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s[0];
    n = s[0].length();
    s[1] = s[0];
    reverse(s[1].begin(), s[1].end());
    for (int it = 0; it < B; it++) {
        p[it] = suffix_array_construction(s[it]);
    }
    for (int i = 2; i < NMAX; i++) {
        pre[i] = pre[i >> 1] + 1;
    }
    for (int it = 0; it < B; it++) {
        for (int i = 0; i < n; i++) {
            sp[i][0][it] = p[it][i];
        }
        for (int j = 1; (1 << j) < n; j++) {
            for (int i = 0; i < n; i++) {
                sp[i][j][it] = min(sp[i][j - 1][it], sp[i + (1 << (j - 1))][j - 1][it]);
            }
        }
    }
    cin >> tc;
    while (tc--) {
        cin >> t[0];
        m = t[0].length();
        if (m == 1 || m > n) {
            continue;
        }
        t[1] = t[0];
        reverse(t[1].begin(), t[1].end());
        vector<int> res[2];
        for (int it = 0; it < B; it++) {
            res[it].assign(m - 1, n + 1);
            int l_bound = 0, r_bound = n - 1;
            for (int i = 0; i < m - 1; i++) {
                int l = l_bound, r = r_bound;
                int left_bound = -1, right_bound = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (can(mid, i, it, 1)) {
                        r = mid - 1;
                        left_bound = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                if (!check(left_bound, i, it)) break;
                l = left_bound, r = r_bound;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (can(mid, i, it, 0)) {
                        l = mid + 1;
                        right_bound = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                assert(left_bound <= right_bound);
                res[it][i] = getRange(left_bound, right_bound, it);
                l_bound = left_bound, r_bound = right_bound;
            }
            if (it) {
                for (int i = 0; i < m - 1; i++) {
                    res[it][i] = (res[it][i] + i);
                    res[it][i] = (n - res[it][i] - 1);
                }
            }
        }
        reverse(res[1].begin(), res[1].end());
        for (int i = 0; i < m - 1; i++) {
            int x = res[0][i];
            int y = res[1][i];
            if (y - x > i) {
                ++ans;
                break;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
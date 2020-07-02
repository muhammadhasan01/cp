#include <bits/stdc++.h>

using namespace std;

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

int n, m, tc;
string t, s;
vector<int> p;

bool can(int x, bool ok) {
    int cnt = 0;
    for (int i = 0, j = p[x]; i < m && j < n; i++, j++) {
        if (s[i] > t[j]) return ok;
        if (s[i] < t[j]) return !ok;
        ++cnt;
    }
    return (cnt == m);
}

bool check(int x) {
    int len = n - p[x];
    if (len < m) return false;
    for (int i = 0, j = p[x]; i < m && j < n; i++, j++) {
        if (s[i] != t[j]) return false;
    }
    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    p = suffix_array_construction(t);
    n = t.length();
    cin >> tc;
    while (tc--) {
        cin >> s;
        m = s.length();
        int l = 0, r = n - 1, left_part = -1, right_part = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid, 0)) {
                r = mid - 1;
                left_part = mid;
            } else {
                l = mid + 1;
            }
        }
        if (!check(left_part)) {
            cout << 0 << '\n';
            continue;
        }
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid, 1)) {
                l = mid + 1;
                right_part = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << right_part - left_part + 1 << '\n';
    }

    return 0;
}
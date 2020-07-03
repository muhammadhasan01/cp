#include <bits/stdc++.h>

using namespace std;

const int N = 150000 + 5;

int n, m;
vector<int> s, p, lcp;
set<int> st[N];
set<int> pos;

vector<int> sort_cyclic_shifts(const vector<int>& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]])
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
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(vector<int> s) {
    s.emplace_back(0);
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(vector<int> const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    if (n == 1) {
        cout << 1 << '\n' << 1 << '\n' << s[0] << '\n';
        return 0;
    }
    p = suffix_array_construction(s);
    lcp = lcp_construction(s, p);
    pos.emplace(-1);
    pos.emplace(n - 1);
    for (int i = 0; i < n - 1; i++) {
        st[lcp[i]].emplace(i);
    }
    long long res = 0;
    int res_len = -1, res_pos = -1;
    multiset<pair<int, int>> lens;
    lens.emplace(n - 1, 0);
    for (int sz = 0; sz < n; sz++) {
        for (auto& e : st[sz]) {
            auto it_1 = pos.lower_bound(e);
            --it_1;
            auto it_2 = pos.upper_bound(e);
            int pos_1 = *it_1, pos_2 = *it_2;
            pair<int, int> curval = make_pair(pos_2 - pos_1 - 1, -(pos_1 + 1));
            auto it = lens.find(curval);
            lens.erase(it);
            lens.emplace(e - pos_1 - 1, -(pos_1 + 1));
            lens.emplace(pos_2 - e - 1, -(e + 1));
            pos.emplace(e);
        }
        pair<int, int> curlarge = *lens.rbegin();
        int frequent = curlarge.first + 1;
        int curpos = -curlarge.second;
        long long curval = (1LL) * (sz + 1) * frequent;
        if (curval > res) {
            res = curval;
            res_len = sz + 1;
            res_pos = curpos;
        }
    }
    if (res <= (1LL) * n) {
        cout << n << '\n' << n << '\n';
        for (int i = 0; i < n; i++) {
            cout << s[i] << (i == n - 1 ? '\n' : ' ');
        }
        return 0;
    }
    cout << res << '\n';
    cout << res_len << '\n';
    for (int i = 0, j = p[res_pos]; i < res_len; i++, ++j) {
        cout << s[j] << (i == res_len - 1 ? '\n' : ' ');
    }

    return 0;
}
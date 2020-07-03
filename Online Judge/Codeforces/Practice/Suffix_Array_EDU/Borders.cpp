#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int n, m;
string s;
vector<int> p, lcp;
set<int> st[N];
set<int> pos;

vector<int> sort_cyclic_shifts(const string& s) {
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

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
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

    cin >> s;
    n = s.length();
    p = suffix_array_construction(s);
    lcp = lcp_construction(s, p);
    pos.emplace(-1);
    pos.emplace(n - 1);
    for (int i = 0; i < n - 1; i++) {
        st[lcp[i]].emplace(i);
    }
    multiset<int> lens;
    lens.emplace(n - 1);
    long long res = (1LL) * n * (n + 1) / 2;
    long long cur = (1LL) * (n - 1) * n / 2;
    for (int sz = 0; sz < n; sz++) {
        for (auto& e : st[sz]) {
            auto it_1 = pos.lower_bound(e);
            --it_1;
            auto it_2 = pos.upper_bound(e);
            int pos_1 = *it_1, pos_2 = *it_2;
            int curval = pos_2 - pos_1 - 1;
            cur -= (1LL) * curval * (curval + 1) / 2;
            auto it = lens.find(curval);
            assert(it != lens.end());
            lens.erase(it);
            int len_1 = e - pos_1 - 1, len_2 = pos_2 - e - 1;
            cur += (1LL) * len_1 * (len_1 + 1) / 2;
            cur += (1LL) * len_2 * (len_2 + 1) / 2;
            if (len_1) lens.emplace(len_1);
            if (len_2) lens.emplace(len_2);
            pos.emplace(e);
        }
        if (lens.empty()) break;
        res += cur;
    }
    cout << res << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

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

vector<int> suffix_array_construction(string const& s) {
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
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

    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    s = s + "$" + t + "#";
    vector<int> p = suffix_array_construction(s);
    vector<int> lcp = lcp_construction(s, p);
    int len = p.size();
    vector<int> place(len);
    for (int i = 0; i < len; i++) {
        if (p[i] < n) {
            place[i] = 1;
        } else if (n + m >= p[i] && p[i] > n) {
            place[i] = 2;
        } else {
            place[i] = 3;
        }
    }
    string answer = "";
    int ans = 0;
    for (int i = 0; i < len - 1; i++) {
        if (place[i] == 3 || place[i + 1] == 3) continue;
        if (place[i] == place[i + 1]) continue;
        if (lcp[i] > ans) {
            answer = s.substr(p[i], lcp[i]);
            ans = lcp[i];
        } else if (lcp[i] == ans) {
            string cur = s.substr(p[i], lcp[i]);
            if (cur < answer) answer = cur;
        }
    }
    cout << answer << '\n';

    return 0;
}
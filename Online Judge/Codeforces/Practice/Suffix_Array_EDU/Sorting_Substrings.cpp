#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const int INF = 2e9;

struct sub {
    int pos, len, lf, rg;
    bool operator<(const sub& other) {
        if (pos == other.pos) {
            if (len == other.len) {
                if (lf == other.lf) {
                    return rg < other.rg;
                }
                return lf < other.lf;
            }
            return len < other.len;
        }
        return pos < other.pos;
    }
};

int n, m;
string str;
vector<int> p, lcp, pos_p;
sub qr[N];
int t[4 * N];

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
    s += char(32);
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

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = lcp[s];
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

int getRange(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return INF;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    return min(getRange(v << 1, s, mid, l, r), getRange(v << 1 | 1, mid + 1, e, l, r));
}

int getIdx(int x, int y) {
    int curpos = pos_p[x];
    int l = 0, r = curpos - 1, ret = curpos;
    int len = y - x + 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (getRange(1, 0, n - 2, mid, curpos - 1) >= len) {
            r = mid - 1;
            ret = mid;
        } else {
            l = mid + 1;
        }
     }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    n = str.size();
    cin >> m;
    if (n == 1) {
        for (int i = 0; i < m; i++) {
            cout << 1 << " " << 1 << '\n';
        }
        return 0;
    }
    p = suffix_array_construction(str);
    pos_p.resize(n);
    for (int i = 0; i < n; i++) {
        pos_p[p[i]] = i;
    }
    lcp = lcp_construction(str, p);
    build(1, 0, n - 2);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        qr[i] = {getIdx(l, r), r - l + 1, l + 1, r + 1};
    }
    sort(qr, qr + m);
    for (int i = 0; i < m; i++) {
        cout << qr[i].lf << " " << qr[i].rg << '\n';
    }

    return 0;
}
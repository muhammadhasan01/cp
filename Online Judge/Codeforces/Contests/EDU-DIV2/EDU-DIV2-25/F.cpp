
#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

const int INF = 1e9;
const int N = 8e3 + 5;
const int K = ceil(log2(N)) + 2;
const int NMAX = (1 << K);

int n;
string s;
int pre[NMAX];
int sp[NMAX][K];
int dp[N], logs[N];
int pos[N];
int can[N];
vector<int> divisor[N];
vector<int> suf, lcp;

int get(int l, int r) {
    int k = pre[r - l + 1];
    return min(sp[l][k], sp[r - (1 << k) + 1][k]);
}

int LOG(int x) {
    int ret = 0;
    while (x > 0) {
        x /= 10;
        ++ret;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    vector<int> suf = suffix_array_construction(s);
    vector<int> lcp = lcp_construction(s, suf);
    for (int i = 0; i < N; i++)
        logs[i] = LOG(i);
    n = s.length();
    for (int i = 0; i < n; i++) {
        pos[suf[i]] = i;
    }
    for (int i = 2; i < NMAX; i++)
        pre[i] = pre[i >> 1] + 1;
    for (int i = 0; i < n - 1; i++) {
        sp[i][0] = lcp[i];
    }
    for (int j = 1; (1 << j) <= n - 1; j++) {
        for (int i = 0; i < n - 1; i++) {
            sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i)
            divisor[j].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            can[i - j + 1] = INF;
        }
        dp[i] = 2 + dp[i - 1];
        can[1] = 1;
        for (int j = i - 1; j >= 1; j--) {
            int len = i - j + 1;
            int cur = INF;
            for (auto& e : divisor[len]) {
                if (e == len) continue;
                int k = j + e;
                if (can[i - k + 1] != e) continue;
                int l = pos[j - 1], r = pos[k - 1];
                if (l > r) swap(l, r);
                int longest = get(l, r - 1);
                if (longest < e)
                    continue;
                can[len] = min(can[len], e);
                int new_len = len / e;
                for (auto& el : divisor[new_len]) {
                    cur = min(cur, el * e + logs[new_len / el]);
                }
                break;
            }
            can[len] = min(len, can[len]);
            cur = min(cur, len + 1);
            dp[i] = min(dp[i], cur + dp[j - 1]);
        }
    }
    cout << dp[n] << '\n';

    return 0;
}
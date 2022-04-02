// Author: Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const int K = 20;
const int MASK = (1 << K);

int n;
string s;
int m;
bool can[N][K];

vector<int> createKMP(const string& s) {
    int n = s.size();
    vector<int> ret(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j && s[i] != s[j]) j = ret[j - 1];
        if (s[i] == s[j]) j++;
        ret[i] = j;
    }
    return ret;
}

int dp[MASK]; // last
int prelen[MASK], bcnt[MASK];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    
    cin >> m;
    vector<int> tlen(m);
    for (int id = 0; id < m; id++) {
        string t;
        cin >> t;
        tlen[id] = t.size();
        int& len = tlen[id];
        vector<int> kmp = createKMP(t);

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j >= len || (j && s[i] != t[j])) j = kmp[j - 1];
            if (s[i] == t[j]) j++;
            if (j == len) {
                can[i + 1][id] = 1; // i - len + 1 .. i
            }
        }
    }
    prelen[0] = n;
    int mxmask = (1 << m);
    for (int i = 1; i < mxmask; i++) {
        bcnt[i] = __builtin_popcount(i);
        for (int j = 0; j < m; j++) {
            int bit = (1 << j);
            if (i & bit) {
                prelen[i] = prelen[i - bit] - tlen[j];
                break;
            }
        } 
    }
    fill(dp, dp + MASK, m);
    dp[0] = -1;
    for (int mask = 1; mask < mxmask; mask++) {
        for (int j = 0; j < m; j++) {
            int bit = (1 << j);
            if ((mask & bit) == 0) continue;

            int bmask = mask - bit;
            if (dp[bmask] == m || !can[prelen[bmask]][j]) continue;
            
            dp[mask] = min(dp[mask], j);
        }
    }
    int anslen = N;
    for (int mask = 1; mask < mxmask; mask++) {
        if (prelen[mask] == 0 && dp[mask] < m) {
            anslen = min(anslen, bcnt[mask]);
        }
    }
    // STUPID SOLUTION, only need to use pair<int, int> >:(
    vector<pair<int, pii>> cand; // last id, (cur mask, initial mask)
    for (int mask = 0; mask < mxmask; mask++) {
        if (prelen[mask] == 0 && dp[mask] < m && bcnt[mask] == anslen) {
            pair<int, pii> temp = mp(dp[mask], mp(mask, mask));
            if (!cand.empty() && temp.first < cand.back().first) cand.clear();
            if (cand.empty() || cand.back().first == temp.first) cand.push_back(temp);
        }
    }
    while (cand.size() > 1) {
        vector<pair<int, pii>> ncand;
        for (auto& cur : cand) {
            int nmask = cur.second.first - (1 << cur.first);
            pair<int, pii> temp = mp(dp[nmask], mp(nmask, cur.second.second));
            if (!ncand.empty() && temp.first < ncand.back().first) ncand.clear();
            if (ncand.empty() || ncand.back().first == temp.first) ncand.push_back(temp);
        }
        cand.swap(ncand);
    }
    cout << anslen << '\n';
    vector<int> ans;

    int cmask = cand[0].second.second;
    ans.emplace_back(dp[cmask]);
    while (ans.size() < anslen) {
        cmask = cmask - (1 << dp[cmask]);
        ans.emplace_back(dp[cmask]);
    }
    for (auto& x : ans) cout << x + 1 << ' '; cout << '\n';

    return 0;
}
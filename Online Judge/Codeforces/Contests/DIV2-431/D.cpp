#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct st {
    int g, p, t, idx;
    bool operator<(const st& other) {
        return t < other.t;
    }
};

int n, h, w;
vector<st> a;
vector<pair<int, int>> ans;
unordered_map<int, int> mp;
vector<deque<int>> dx, dy;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w >> h;
    a.resize(n);
    ans.resize(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i].g >> a[i].p >> a[i].t;
        st.insert(a[i].t - a[i].p);
        a[i].idx = i;
    }
    int ord = 0;
    for (auto& e : st) mp[e] = ++ord;
    dx.resize(ord + 1); dy.resize(ord + 1);
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].g == 1) {
            int pos = mp[a[i].t - a[i].p];
            if (!dx[pos].empty()) {
                int temp = a[i].idx;
                a[i].idx = dx[pos].back();
                dx[pos].pop_back();
                dx[pos].emplace_front(temp);
            }
            dy[pos].emplace_back(a[i].idx);
        } else {
            int pos = mp[a[i].t - a[i].p];
            if (!dy[pos].empty()) {
                int temp = a[i].idx;
                a[i].idx = dy[pos].back();
                dy[pos].pop_back();
                dy[pos].emplace_front(temp);
            }
            dx[pos].emplace_back(a[i].idx);
        }
    }
    vector<int> cntx(ord + 1), cnty(ord + 1);
    for (int i = 0; i < n; i++) {
        if (a[i].g == 1) {
            int pos = mp[a[i].t - a[i].p];
            ans[dy[pos][cnty[pos]]] = make_pair(a[i].p, h);
            ++cnty[pos];
        } else {
            int pos = mp[a[i].t - a[i].p];
            ans[dx[pos][cntx[pos]]] = make_pair(w, a[i].p);
            ++cntx[pos];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }

    return 0;
}
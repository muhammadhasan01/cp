#include <bits/stdc++.h>

using namespace std;

int addEdge(int x) {
    cout << "+ " << x << endl;
    int ret;
    cin >> ret;
    if (ret == -2) {
        exit(0);
    }
    return ret;
}

int queryPair(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int ret;
    cin >> ret;
    if (ret == -2) {
        exit(0);
    }
    return ret;
}

void queryAnswer(vector<vector<int>> ans) {
    if (ans.size() == 1) {
        ans.emplace_back(ans[0]);
    }
    vector<int> p;
    for (auto v : ans) {
        for (int x : v) {
            p.emplace_back(x);
        }
    } 
    int n = p.size();
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << p[i];
        if (i == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    int ret;
    cin >> ret;
    if (ret == -2) {
        exit(0);
    }
}

void solve() {
    int n;
    cin >> n;
    addEdge(n + 1);
    addEdge(n);
    vector<int> pos(n + 1);
    vector<int> ord(n + 1);
    for (int i = 1, cur = n; i <= n; i += 2) {
        ord[i] = cur;
        cur--;
    }
    for (int i = 2, cur = 1; i <= n; i += 2) {
        ord[i] = cur;
        cur++;
    }
    for (int i = 1; i <= n; i++) {
        pos[ord[i]] = i;
    }
    vector<int> dist(n + 1);
    for (int x = 2; x <= n; x++) {
        dist[x] = queryPair(1, x);
    }
    int maxDist = *max_element(dist.begin(), dist.end());

    vector<vector<int>> ans;

    auto handleAll = [&](int val, int endPos, int endVal) -> void {
        vector<int> p(n + 1);
        p[1] = val;
        p[endPos] = endVal;
        vector<set<int>> vals(n + 1);

        for (int x = 1; x <= n; x++) {
            int curVal = abs(ord[x] - ord[val]);
            vals[curVal].emplace(x);
        }

        for (int x = 2; x <= n; x++) {
            if (x == endPos) {
                continue;
            }
            int res = queryPair(endPos, x);
            if (endVal == n) {
                if (res > dist[x]) {
                    p[x] = *vals[dist[x]].rbegin();
                } else {
                    p[x] = *vals[dist[x]].begin();
                }
            } else {
                if (res > dist[x]) {
                    p[x] = *vals[dist[x]].begin();
                } else {
                    p[x] = *vals[dist[x]].rbegin();
                }
            }
        }

        ans.emplace_back(p);
    };

    auto handleEndpoint = [&](int val) -> void {
        vector<int> endPoint;
        for (int x = 2; x <= n; x++) {
            if (dist[x] == maxDist) {
                endPoint.emplace_back(x);
            }
        }
        if (endPoint.size() == 2) {
            handleAll(val, endPoint[0], n);
            handleAll(val, endPoint[1], n);
        } else {
            int endVal = (pos[val] > n / 2 ? ord[1] : ord[n]);
            handleAll(val, endPoint[0], endVal);
        }
    };

    if (n % 2 == 1 && maxDist == n / 2) {
        handleEndpoint(ord[maxDist + 1]);
    } else {
        for (int val : {ord[maxDist + 1], ord[n - maxDist]}) {
            handleEndpoint(val);
        }
    }

    queryAnswer(ans);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}
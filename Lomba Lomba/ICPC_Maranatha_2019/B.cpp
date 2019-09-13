#include <bits/stdc++.h>
using namespace std;

string a;
int f[100];
vector<int> par;
vector<int> sz;
vector<pair<int,int>> val;

int find(int x) {
    return (par[x] == x ? x : find(par[x]));
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb) {
        if (sz[pa] < sz[pb]) swap(pa, pb);
        sz[pa] += sz[pb];
        par[pb] = pa;
    }
}

pair<int,int> gabung(pair<int,int> a, pair<int,int> b) {
    if (a.first > b.first) swap(a, b);
    bool ok1 = false, ok2 = false;
    if (a.first > a.second) {
        ok1 = true;
    }
    if (b.first > b.second) {
        ok2 = true;
    }
    if (ok1 && ok2) {
        return {a.first, max(a.second, b.second)}; // ok
    } else if (ok1) {
        return {a.first, a.second}; // ok
    } else if (ok2) {
        if (a.second >= b.first) {
            if (b.second >= a.first) {
                return {1, 50};
            } else {
                return {a.first, b.second};
            }
        } else if (b.second >= a.first) {
            return {b.first, max(a.second, b.second)};
        } else {
            return {-1, -1};
        }
    } else {
        if (a.second >= b.first) {
            return {a.first, max(a.second, b.second)};
        } else {
            return {-1, -1};
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    pair<int,int> has = gabung({a, b}, {c, d});
    cout << has.first << " " << has.second << '\n';*/

    getline(cin, a);
    vector<pair<int, int>> v;
    a = '#' + a;
    string temp = "";
    int x = -1, y = -1, cnt = 0;
    for (int i = 1; i <= (int) a.size(); i++) {
        if ('0' <= a[i] && a[i] <= '9') {
            temp += a[i];
        } else if (temp != ""){
            cnt++;
            if (cnt & 1) {
                x = stoi(temp);
            } else {
                y = stoi(temp);
                v.push_back({x, y});
            }
            temp = "";
        }
    }
    int n = v.size();
    par.resize(n);
    sz.resize(n);
    val.resize(n);
    for (int i = 0; i < n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        val[i] = v[i];
    }
    pair<int,int> sal = {-1, - 1};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int p1 = find(i), p2 = find(j);
            pair<int,int> temp = gabung(val[p1], val[p2]);
            if (temp == sal) continue;
            merge(i, j);
            int p = find(i);
            val[p] = temp;
        }
    }
    vector<bool> vis(n, false);
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        int k = find(i);
        if (vis[k] == 0) {
            vis[k] = 1;
            res.push_back(val[k]);
        }
    }
    sort(res.begin(), res.end());
    cout << "[";
    int m = res.size();
    for (int i = 0; i < m; i++) {
        cout << "(" << res[i].first << ", " << res[i].second << ")" << (i == m - 1 ? "]" : ", ");
    }
    cout << '\n';

    return 0;
}

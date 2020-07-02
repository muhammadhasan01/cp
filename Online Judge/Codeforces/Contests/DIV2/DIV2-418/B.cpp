#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
int a[N], b[N], p[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<bool> vis(n + 1);
    vector<int> idx;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            p[i] = a[i];
            vis[a[i]] = 1;
        } else {
            idx.emplace_back(i);
        }
    }
    vector<int> available;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) available.emplace_back(i);
    }
    int len = idx.size();
    if (len == 1) {
        p[idx[0]] = available[0];
    } else if (len == 2) {
        for (int i = 0; i < len; i++) p[idx[i]] = available[i];
        bool flag = true;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != p[i]) ++cnt;
        }
        if (cnt != 1) flag = false;
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i] != p[i]) ++cnt;
        }
        if (cnt != 1) flag = false;
        if (!flag) swap(p[idx[0]], p[idx[1]]);
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
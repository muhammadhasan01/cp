#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
string s[N];
int p[N], id[N];
vector<int> v[N];
vector<pair<int, int>> w[N];
int res[N][N];

bool check() {
    for (int i = 0; i < n - 1; i++) {
        int len_1 = s[id[i]].size();
        int len_2 = s[id[i + 1]].size();
        int cur = abs(len_1 - len_2);
        for (int j = 0; j < min(len_1, len_2); j++) {
            if (s[id[i]][j] != s[id[i + 1]][j]) cur++;
        }
        res[i][i + 1] = cur;
        res[i + 1][i] = cur;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            res[i][j] = res[i][j - 1] + res[j - 1][j];
            res[j][i] = res[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] != res[p[i]][p[j]]) return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        v[i].resize(n), w[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            w[i][j] = make_pair(v[i][j], j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                if (v[i][j]) {
                    cout << "Aku sudah menyangka tidak akan semudah ini Ferguso" << '\n';
                    return;
                }
            } else if (v[i][j] != v[j][i]) {
                cout << "Aku sudah menyangka tidak akan semudah ini Ferguso" << '\n';
                return;
            }
        }
    }
    if (n == 1) {
        cout << s[0] << '\n';
        return;
    }
    int maks = 0, row = -1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i][j] > maks) {
                maks = v[i][j];
                row = i;
            }
        }
    }
    assert(row != -1);
    sort(w[row].begin(), w[row].end());
    p[row] = 0, id[0] = row;
    for (int i = 1; i < n; i++) {
        p[w[row][i].second] = i;
        id[i] = w[row][i].second;
    }
    if (!check()) {
        p[row] = n - 1, id[n - 1] = row;
        for (int i = 1; i < n; i++) {
            p[w[row][i].second] = n - i - 1;
            id[n - i - 1] = w[row][i].second;
        }
        if (!check()) {
            cout << "Aku sudah menyangka tidak akan semudah ini Ferguso" << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[id[i]] << (i == n - 1 ? '\n' : ' ');
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}
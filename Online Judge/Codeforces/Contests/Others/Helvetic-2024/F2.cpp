#include <bits/stdc++.h>

using namespace std;

const int K = 2;
const string RG = "RG";
const string BG = "BG";
const string C = "C";
const string U = "U";
const string L = "L";
const string D = "D";
const string R = "R";
const string T = "T";
const string RED = "RED";
const string BLUE = "BLUE";
const string BLUDGER = ".B";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector a(n, vector<string>(m));
    vector st(n, vector<set<string>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            st[i][j].emplace(a[i][j]);
        }
    }
    vector<int> score(K);
    map<string, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mp[a[i][j]] = {i, j};
        }
    }
    int q;
    cin >> q;
    for (int it = 0; it < q; it++) {
        string entity, action;
        cin >> entity >> action;
        if (action == C) {
            string useless;
            cin >> useless;
        }
        auto& [i, j] = mp[entity];
        st[i][j].erase(entity);
        if (action == U) {
            i--;
        } else if (action == L) {
            j--;
        } else if (action == R) {
            j++;
        } else if (action == D) {
            i++;
        } else if (action == T) {
            if (a[i][j] == RG || a[i][j] == BG) {
                int red = a[i][j] == BG;
                score[red]++;
                cout << it << " " << (red ? "RED" : "BLUE") << " GOAL\n";
            }
        }
        st[i][j].emplace(entity);
        if (mp.count(BLUDGER)) {
            auto [bi, bj] = mp[BLUDGER];
            vector<string> E;
            for (string e : st[bi][bj]) {
                if (e[0] == 'R' || e[0] == 'B') {
                    if ('0' <= e[1] && e[1] <= '9') {
                        E.emplace_back(e);
                    }
                }
            }
            for (string e : E) {
                st[bi][bj].erase(e);
                cout << it << " " << e << " ELIMINATED\n";
            }
        }
     }
     cout << "FINAL SCORE: " << score[1] << ' ' << score[0] << '\n';
    
    return 0;
}
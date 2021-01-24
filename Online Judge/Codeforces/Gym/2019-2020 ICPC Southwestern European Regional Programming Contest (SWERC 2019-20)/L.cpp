// author : donbasta
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

const int INF = 1e9;
const int N = 10;
bool vis[N + 5][N + 5];
string s[N + 5];
int n;
vector<bool> visTmp;
vector<pair<int, int>> Borders;
map<pair<int, int>, int> mp;

inline bool valid(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < n); }

inline int mex(vector<int>& ve) {
    if (ve.empty()) return 0;
    set<int> se;
    for (auto e : ve) se.emplace(e);
    int i = 0;
    while (se.count(i)) i++;
    return i;
}

int calc(int v) {
    vector<pair<int, int>> part;
    queue<pair<int, int>> lul;
    lul.emplace(Borders[v]);
    visTmp[v] = true;
    part.emplace_back(Borders[v]);
    while(!lul.empty()) {
        auto now = lul.front();
        lul.pop();
        for (int i = 0; i < 4; i++) {
            int xx = now.first + dx[i];
            int yy = now.second + dy[i];
            if (!valid(xx, yy)) continue;
            if (mp.find(make_pair(xx, yy)) == mp.end()) continue;
            if (visTmp[mp[make_pair(xx, yy)]]) continue;
            visTmp[mp[make_pair(xx, yy)]] = true;
            lul.emplace(xx, yy);
            part.emplace_back(xx, yy);
        }
    }
    int sz = (int)part.size();
    map<pair<int, int>, int> mop;
    for (int i = 0; i < sz; i++) {
        mop[part[i]] = i;
    }
    vector<int> dp(1 << sz, INF);
    dp[0] = 0;
    for (int i = 1; i < (1 << sz); i++) {
        bool gabisa = false;
        vector<int> tmp;
        vector<bool> gaboleh(sz);
        for (int j = 0; j < sz; j++) {
            if (!((i >> j) & 1)) {
                pair<int, int> loc = part[j];
                for (int k = 0; k < 4; k++) {
                    int xx = loc.first + dx[k], yy = loc.second + dy[k];
                    if (valid(xx, yy) && mop.find(make_pair(xx, yy)) != mop.end()) {
                        int lol = mop[make_pair(xx, yy)];
                        if (!((i >> lol) & 1)) {
                            gabisa = true;
                            break;
                        }
                        gaboleh[lol] = true;
                    }
                }
            }
            if (gabisa) { break; }
        }
        if (gabisa) { continue; }
        for (int j = 0; j < sz; j++) {
            if (!((i >> j) & 1)) continue;
            if (gaboleh[j]) continue;
            tmp.emplace_back(dp[i ^ (1 << j)]);
        }
        dp[i] = mex(tmp);
    }
    return dp[(1 << sz) - 1];
}

int proses(int x, int y) {
    mp.clear();
    Borders.clear();

    vis[x][y] = 1;
    queue<pair<int, int>> Q;
    Q.emplace(x, y);
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = now.first + dx[i];
            int yy = now.second + dy[i];
            if (!valid(xx, yy)) continue;
            if (vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            if (s[xx][yy] == '.') {
                Borders.emplace_back(xx, yy);
            } else if (s[xx][yy] == '*') {
                Q.emplace(xx, yy);
            }
        }
    }
    int sz = (int)Borders.size();
    visTmp.assign(sz, false);
    for (int i = 0; i < sz; i++) {
        mp[Borders[i]] = i;
    }
    int ret = 0;
    for (int i = 0; i < sz; i++) {
        if (!visTmp[i]) {
            ret ^= calc(i);
        }
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int state = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*' && !vis[i][j]) {
                int tempGrundy = proses(i, j);
                state ^= tempGrundy;
            }
        }
    }
    string winner;
    winner = (state ? "First" : "Second");
    cout << winner << " player will win\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}
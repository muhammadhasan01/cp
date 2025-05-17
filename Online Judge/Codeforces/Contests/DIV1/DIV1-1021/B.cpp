#include <bits/stdc++.h>

using namespace std;

static const int MOD = 1e9 + 7;

inline int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> odd(k + 1);
    for (auto &p : odd) {
        cin >> p.first >> p.second;
    }

    vector<vector<pair<int, int>>> C(k);
    set<long long> oddSet;

    for (auto &p : odd) {
        oddSet.insert(((long long)p.first << 32) | p.second);
    }

    auto inGrid = [&](int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

    static const int DX[4] = {1, -1, 0, 0};
    static const int DY[4] = {0, 0, 1, -1};

    bool impossible = false;

    for (int i = 0; i < k; i++) {
        auto [x1, y1] = odd[i];
        auto [x3, y3] = odd[i + 1];
        vector<pair<int, int>> tmp;

        for (int d1 = 0; d1 < 4; d1++) {
            int nx1 = x1 + DX[d1];
            int ny1 = y1 + DY[d1];
            if (!inGrid(nx1, ny1)) {
                continue;
            }
            for (int d2 = 0; d2 < 4; d2++) {
                int nx3 = x3 + DX[d2];
                int ny3 = y3 + DY[d2];
                if (nx1 == nx3 && ny1 == ny3) {
                    long long code = ((long long)nx1 << 32) | ny1;
                    if (!oddSet.count(code)) {
                        tmp.emplace_back(nx1, ny1);
                    }
                }
            }
        }

        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

        if (tmp.empty()) {
            impossible = true;
            break;
        }

        C[i] = move(tmp);
    }

    if (impossible) {
        cout << 0 << "\n";
        return;
    }

    map<long long, vector<int>> segsOf;

    vector<int> deg(k);
    for (int i = 0; i < k; i++) {
        deg[i] = (int)C[i].size();
        for (auto &u : C[i]) {
            long long code = ((long long)u.first << 32) | u.second;
            segsOf[code].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 0; i < k; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }

    set<long long> usedCell;
    vector<long long> assigned(k, -1LL);

    while (!q.empty() && !impossible) {
        int i = q.front();
        q.pop();

        if (assigned[i] != -1LL) {
            continue;
        }

        long long pick = -1;
        for (auto &u : C[i]) {
            long long code = ((long long)u.first << 32) | u.second;
            if (!usedCell.count(code)) {
                pick = code;
                break;
            }
        }

        if (pick == -1) {
            impossible = true;
            break;
        }

        assigned[i] = pick;
        usedCell.insert(pick);

        for (int j : segsOf[pick]) {
            if (assigned[j] == -1LL) {
                int nd = 0;
                for (auto &u : C[j]) {
                    long long code = ((long long)u.first << 32) | u.second;
                    if (code != pick) {
                        C[j][nd++] = u;
                    }
                }
                deg[j] = nd;
                C[j].resize(nd);
                if (deg[j] == 0) {
                    impossible = true;
                    break;
                }
                if (deg[j] == 1) {
                    q.push(j);
                }
            }
        }
    }

    if (impossible) {
        cout << 0 << "\n";
        return;
    }

    vector<vector<long long>> segAdj(k);
    map<long long, vector<int>> cellAdj;

    for (int i = 0; i < k; i++) {
        if (assigned[i] < 0) {
            for (auto &u : C[i]) {
                long long code = ((long long)u.first << 32) | u.second;
                segAdj[i].push_back(code);
                cellAdj[code].push_back(i);
            }
        }
    }

    vector<bool> visSeg(k, false);
    long long ans = 1;
    for (int i = 0; i < k; i++) {
        if (assigned[i] < 0 && !visSeg[i]) {
            queue<pair<bool, long long>> bfsQ;
            bfsQ.emplace(true, i);
            visSeg[i] = true;

            int cntSeg = 0;
            int cntCell = 0;
            set<long long> seenCells;

            while (!bfsQ.empty()) {
                auto [isSeg, id] = bfsQ.front();
                bfsQ.pop();

                if (isSeg) {
                    cntSeg++;
                    for (auto &c : segAdj[(int)id]) {
                        if (!seenCells.count(c)) {
                            seenCells.insert(c);
                            bfsQ.emplace(false, c);
                        }
                    }
                } else {
                    cntCell++;
                    for (int s : cellAdj[id]) {
                        if (!visSeg[s]) {
                            visSeg[s] = true;
                            bfsQ.emplace(true, s);
                        }
                    }
                }
            }

            if (cntCell == cntSeg + 1) {
                ans = ans * (cntSeg + 1) % MOD;
            } else if (cntCell == cntSeg) {
                ans = ans * 2 % MOD;
            } else {
                ans = 0;
                break;
            }
        }
    }
    cout << ans << "\n";
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    return 0;
}

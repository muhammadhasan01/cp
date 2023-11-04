#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    auto getMoves = [&](vector<int> v, int l, int r) -> vector<pair<int, int>> {
        vector<pair<int, int>> moves;
        for (int i = l; i <= r; i++) {
            pair<int, int> mn = make_pair(INF, INF);
            for (int j = i; j <= r; j++) {
                mn = min(mn, make_pair(v[j], j));
            }
            auto [_, pos] = mn;
            if (i == pos) {
                continue;
            }
            swap(v[i], v[pos]);
            moves.emplace_back(i, pos);
        }
        return moves;
    };

    auto applyMoves = [&](vector<int>& v, vector<pair<int, int>>& moves) -> void {
        for (auto [l, r] : moves) {
            swap(v[l], v[r]);
        }
    };

    vector<pair<int, int>> ans;
    {
        vector<pair<int, int>> moves = getMoves(a, 0, n - 1);
        applyMoves(a, moves);
        applyMoves(b, moves);
        ans.insert(ans.end(), moves.begin(), moves.end());
    }
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && a[i] == a[j + 1]) {
            ++j;
        }
        vector<pair<int, int>> moves = getMoves(b, i, j);
        applyMoves(a, moves);
        applyMoves(b, moves);
        ans.insert(ans.end(), moves.begin(), moves.end());
        i = j;
    }
    if (is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end())) {
        cout << ans.size() << '\n';
        for (auto [l, r] : ans) {
            cout << l + 1 << ' ' << r + 1 << '\n';
        }
        return;
    }
    cout << -1 << '\n';
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
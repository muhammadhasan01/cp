#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int BLOCK = 750;
const int NUM_BLOCK = N / BLOCK + 3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<pair<long long, int>>> bl(NUM_BLOCK);
    vector<long long> addition(NUM_BLOCK);
    int num_block = 0;
    auto build = [&]() -> void {
        for (int i = 1, b = 1; i <= n; i += BLOCK, b++) {
            for (int j = i; j <= min(n, i + BLOCK - 1); j++) {
                bl[b].emplace_back(a[j], j);
            }
            sort(bl[b].begin(), bl[b].end());
            num_block++;
        }
    };
    auto get_block = [&](int pos) -> int {
        return (pos + BLOCK - 1) / BLOCK;
    };
    auto add_block = [&](int b, int l, int r, long long x) -> void {
        for (auto& [val, id] : bl[b]) {
            if (l <= id && id <= r) {
                val += x;
            }
        }
        sort(bl[b].begin(), bl[b].end());
    };
    auto add_val = [&](int l, int r, long long x) -> void {
        int lb = get_block(l);
        int rb = get_block(r);
        if (lb == rb) {
            add_block(lb, l, r, x);
            return;
        }
        add_block(lb, l, n, x);
        for (int b = lb + 1; b <= rb - 1; b++) {
            addition[b] += x;
        }
        add_block(rb, 1, r, x);
    };
    auto get_answer = [&](long long y) -> int {
        int lft = n + 1, rgt = 0;
        for (int b = 1; b <= num_block; b++) {
            // find left
            int pos_left = -1;
            {
                int l = 0, r = (int) bl[b].size() - 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (bl[b][mid].first + addition[b] >= y) {
                        r = mid - 1;
                        pos_left = mid;
                    } else {
                        l = mid + 1;
                    }
                }
            }
            if (pos_left == -1 || bl[b][pos_left].first + addition[b] != y) {
                continue;
            }
            lft = min(lft, bl[b][pos_left].second);
            // find right
            int pos_right = -1;
            {
                int l = 0, r = (int) bl[b].size() - 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (bl[b][mid].first + addition[b] <= y) {
                        l = mid + 1;
                        pos_right = mid;
                    } else {
                        r = mid - 1;
                    }
                }
            }
            rgt = max(rgt, bl[b][pos_right].second);
        }
        if (lft == n + 1) {
            return -1;
        }
        return rgt - lft;
    };
    build();
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            add_val(l, r, x);
        } else if (tp == 2) {
            int y;
            cin >> y;
            cout << get_answer(y) << '\n';
        }
    }
    
    return 0;
}
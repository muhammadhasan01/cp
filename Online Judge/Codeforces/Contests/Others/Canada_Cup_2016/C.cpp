#include <bits/stdc++.h>

using namespace std;

const int K = 26;

void dismiss() {
    cout << "Impossible\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int n = str.size();
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = str[i] - 'A';
    }
    vector<vector<int>> freq(K);
    for (int i = 0; i < n; i++) {
        freq[nums[i]].emplace_back(i);
    }
    auto get_char = [&](int x) -> char {
        return char(int('A') + x);
    };
    vector<vector<char>> ans(3, vector<char>(K + 1));
    for (int i = 0; i < K; i++) {
        int len = freq[i].size();
        if (len == 1) {
            continue;
        }
        assert(len == 2);
        int x = freq[i][0], y = freq[i][1];
        int dist = y - x - 1;
        if (dist == 0) {
            dismiss();
        }
        int col_max = K / 2;
        int col = dist / 2;
        int cur_col = col_max - col;
        ans[1][cur_col] = get_char(i);
        for (int j = x + 1, sz = 1, rv = 1; j <= y - 1; j++, sz++) {
            char cc = str[j];
            if (cur_col + sz <= col_max) {
                ans[1][cur_col + sz] = cc;
            } else {
                ans[2][col_max - rv + 1] = cc;
                rv++;
            }
        }
        vector<char> characters;
        for (int j = y + 1; j < n; j++) {
            characters.emplace_back(str[j]);
        }
        for (int j = 0; j < x; j++) {
            characters.emplace_back(str[j]);
        }
        int dist_c = characters.size();
        for (int j = 0, sz = 1; j < dist_c; j++, sz++) {
            char cc = characters[j];
            if (cur_col - sz > 0) {
                ans[1][cur_col - sz] = cc;
            } else {
                ans[2][sz - cur_col + 1] = cc;
            }
        }
    }
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= K / 2; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}
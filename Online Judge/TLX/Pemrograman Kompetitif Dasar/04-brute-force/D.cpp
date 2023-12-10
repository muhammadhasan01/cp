#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string subtask;
    int X;
    cin >> subtask >> X;
    int n, r, y, j;
    cin >> n >> r >> y >> j;
    vector<pair<int, char>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i].first >> g[i].second;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for (int i = 0; i < n - r; i++) {
        p[i] = 0;
    }
    vector<int> scores;
    do {
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (p[i] == 0) {
                continue;
            }
            idx.emplace_back(i);
        }
        sort(idx.begin(), idx.end(), [&](int& lhs, int& rhs) {
            return p[lhs] < p[rhs];
        });
        bool sure = false;
        char last = '#';
        int score = 0;
        for (int i : idx) {
            if (last == 'Y') {
                sure = true;
            }
            if (last == 'P') {
                score += (g[i].first * 2);
            } else if (last == 'L') {
                score += (g[i].first / 2);
            } else {
                score += g[i].first;
            }
            if (sure) {
                score += y;
            }
            last = g[i].second;
        }
        scores.emplace_back(score);
    } while (next_permutation(p.begin(), p.end()));
    sort(scores.begin(), scores.end());
    int len = (int) scores.size();
    while (j--) {
        int score;
        cin >> score;
        int pos = upper_bound(scores.begin(), scores.end(), score) - scores.begin();
        cout << len - pos << '\n';
    }
    
    return 0;
}
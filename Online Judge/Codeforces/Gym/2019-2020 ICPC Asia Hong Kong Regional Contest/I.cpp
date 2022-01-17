#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<set<pair<int, int>>> obs(n + 1);
    vector<long long> seen(n + 1);
    vector<vector<pair<int, int>>> places(m + 1);
    vector<long long> remains(m + 1);
    vector<int> answers;
    int last = 0;
    auto inp = [&](int& x) -> void {
        cin >> x;
        x = (x ^ last);
    };
    auto put = [&](int id) -> void {
        int len = places[id].size();
        int now_wait = (remains[id] + len - 1) / len;
        for (auto& [cam, rem] : places[id]) {
            rem = seen[cam];
            obs[cam].emplace(rem + now_wait, id);
        }
    };
    auto check = [&](int id) -> void {
        int len = places[id].size();
        int was_wait = (remains[id] + len - 1) / len;
        for (auto& [cam, rem] : places[id]) {
            remains[id] -= (seen[cam] - rem);
            obs[cam].erase(make_pair(rem + was_wait, id));
        }
        if (remains[id] <= 0) {
            answers.emplace_back(id);
        } else {
            put(id);
        }
    };
    auto add_seen = [&](int x, int y) -> void {
        seen[x] += y;
        while (!obs[x].empty()) {
            auto [rem, id] = *obs[x].begin();
            if (rem > seen[x]) {
                break;
            }
            check(id);
        }
    };
    for (int tt = 1, id = 1; tt <= m; tt++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int y, k;
            inp(y);
            cin >> k;
            remains[id] = y;
            for (int i = 0; i < k; i++) {
                int x;
                inp(x);
                places[id].emplace_back(x, -1);
            }
            put(id);
            id++;
        } else if (tp == 2) {
            int x, y;
            inp(x);
            inp(y);
            answers.clear();
            add_seen(x, y);
            last = (int) answers.size();
            sort(answers.begin(), answers.end());
            cout << last << " \n"[last == 0];
            for (int i = 0; i < last; i++) {
                cout << answers[i] << " \n"[i == last - 1];
            }
        }
    }
    
    return 0;
}
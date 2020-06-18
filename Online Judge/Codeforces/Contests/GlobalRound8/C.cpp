#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int N = 1000;

int n;
vector<pair<int, int>> ans;
map<pair<int, int>, bool> mp;

void get() {
    if (n == 1) {
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                if (i <= 2 && j <= 2) continue;
                if (i >= 4 && j >= 4) continue;
                if (i == 2 && j == 4) continue;
                if (i == 4 && j == 2) continue;
                ans.emplace_back(i, j);
            }
        }
        return;
    }
    int cur = n;
    int pos = 1, it = 1, cnt = 0;
    while (cur > 0) {
        ans.emplace_back(pos, it);
        mp[make_pair(pos, it)] = 1;
        cur--;
        ++it;
        ++cnt;
        if (cnt % 2 == 0) {
            pos++;
            it--;
        }
    }
    vector<pair<int, int>> res;
    for (auto e : ans) {
        for (int i = 0; i < 4; i++) {
            int cx = e.first + dx[i];
            int cy = e.second + dy[i];
            pair<int, int> cur = make_pair(cx, cy);
            if (mp[cur] == 1) continue;
            mp[cur] = 1;
            res.emplace_back(cx, cy);
        }
    }
    for (auto e : res) ans.push_back(e);
    int curpos = 1;
    while (curpos <= N) {
        ans.emplace_back(curpos, -1);
        ++curpos;
    }
    if (n % 2 == 0) {
        curpos = pos - 1;
        it += 2;
    } else {
        curpos = pos + 1;
        --it;
    }
    while (curpos <= N) {
        ans.emplace_back(curpos, it);
        curpos++;
    }
    for (int i = 0; i < it; i++) {
        ans.emplace_back(N, i);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    get();
    map<pair<int, int>, bool> uniq;
    vector<pair<int, int>> result;
    for (auto e : ans) {
        if (uniq[e] == 1) continue;
        uniq[e] = 1;
        result.push_back(e);
    }
    ans = result;
    cout << ans.size() << '\n';
    for (auto& e : ans) {
        cout << e.first << " " << e.second << '\n';
    }
    // int len = ans.size();
    // assert(len <= 500000);
    // int res = 0, tot = 0;
    // map<pair<int, int>, bool> mpz;
    // for (auto& e : ans) {
    //     mp[e] = 1;
    //     assert(mpz[e] == 0);
    //     mpz[e] = 1;
    // }
    // for (auto& e : ans) {
    //     for (int i = 0; i < 4; i++) {
    //         int cx = e.first + dx[i];
    //         int cy = e.second + dy[i];
    //         pair<int, int> cur = make_pair(cx, cy);
    //         if (mp[cur] == 1) {
    //             ++tot;
    //         }
    //     }
    //     if (tot % 2 != 0) {
    //         cerr << tot << " => " << e.first << " dan " << e.second << '\n';
    //         assert(false);
    //     }
    //     if (tot == 4) ++res;
    //     tot = 0;
    // }
    // assert(res == n);

    return 0;
}
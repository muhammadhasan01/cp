#include <bits/stdc++.h>

using namespace std;

const int K = 2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> values(K);
    cin >> values[1] >> values[0];
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        if (abs(values[0]) != a[0] || values[1] != 0) {
            cout << "No" << '\n';
            return 0;
        }
        cout << "Yes" << '\n';
        cout << (values[0] == a[0] ? 'L' : 'R') << '\n';
        return 0;
    }

    auto getSign = [&](vector<int>& A, int S, int V) -> vector<bool> {
        int m = (int) A.size();
        if (m == 1) {
            vector<bool> ret;
            if (abs(A[0]) != abs(V)) {
                return ret;
            }
            ret.resize(1);
            if (A[0] == V) {
                ret[0] = true;
            } else if (A[0] == -V) {
                ret[0] = false;
            }
            return ret;
        }
        int target = (S - V) / 2;
        int h = m / 2;
        map<int, int> mp;
        for (int mask = 0; mask < (1 << h); mask++) {
            int sum = 0;
            for (int i = 0; i < h; i++) {
                if (mask & (1 << i)) {
                    sum += A[i];
                }
            }
            mp[sum] = mask;
        }
        int other = m - h;
        pair<int, int> M = {-1, -1};
        for (int mask = 0; mask < (1 << other); mask++) {
            int sum = 0;
            for (int i = 0; i < other; i++) {
                if (mask & (1 << i)) {
                    sum += A[i + h];
                }
            }
            int cur = target - sum;
            if (mp.find(cur) == mp.end()) {
                continue;
            }
            M = {mp[cur], mask};
            break;
        }
        vector<bool> ret;
        if (M.first == -1) {
            return ret;
        }
        ret.resize(m);
        for (int i = 0; i < h; i++) {
            if (M.first & (1 << i)) {
                ret[i] = false;
            } else {
                ret[i] = true;
            }
        }
        for (int i = 0; i < other; i++) {
            if (M.second & (1 << i)) {
                ret[i + h] = false;
            } else {
                ret[i + h] = true;
            }
        }
        return ret;
    };

    vector<vector<int>> A(K);
    vector<int> sum(K);
    for (int i = 0; i < n; i++) {
        int p = i % 2;
        A[p].emplace_back(a[i]);
        sum[p] += a[i];
    }
    vector<vector<bool>> signs(K);
    for (int i = 0; i < K; i++) {
        if (abs(sum[i] - values[i]) % 2 == 1) {
            cout << "No" << '\n';
            return 0;
        }
        signs[i] = getSign(A[i], sum[i], values[i]);
        if (signs[i].empty()) {
            cout << "No" << '\n';
            return 0;
        }
    }
    vector<bool> allSigns(n);
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        if (i % 2 == 0) {
            allSigns[i] = signs[0][j++];
        } else {
            allSigns[i] = signs[1][k++];
        }
    }
    cout << "Yes" << '\n';
    vector<char> ans(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (i == 0 || allSigns[i - 1]) {
                ans[i] = allSigns[i] ? 'L' : 'R';
            } else {
                ans[i] = allSigns[i] ? 'R' : 'L';
            }
        } else {
            if (allSigns[i - 1]) {
                ans[i] = allSigns[i] ? 'R' : 'L';
            } else {
                ans[i] = allSigns[i] ? 'L' : 'R';
            }
        }
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

string str;
int subsoal;
int n, k, q;

int ask(vector<int>& v) {
    int m = (int) v.size();
    assert(m > 0);
    cout << m << " ";
    for (int i = 0; i < m; i++) {
        cout << v[i];
        if (i + 1 < m) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    string ret;
    cin >> ret;
    if (ret == "tidak") {
        return 0;
    }
    if (ret == "bisajadi") {
        return 1;
    }
    assert(ret == "ya");
    return 2;
}

void solveForOne() {
    vector<int> S;
    for (int i = 1; i <= n; i++) {
        vector<int> v = {i};
        int cur = ask(v);
        if (cur == 2) {
            return;
        }
        if (cur == 1) {
            S.emplace_back(i);
        }
    }
    assert(ask(S) == 2);
}

void solveSubtaskFive() {
    int l = 1, r = n, at = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        vector<int> v = {mid};
        int cur = ask(v);
        if (cur == 2) {
            return;
        }
        if (cur == 1) {
            l = mid + 1;
            at = mid;
        } else {
            r = mid - 1;
        }
    }
    assert(at != -1);
    vector<int> S(at);
    iota(S.begin(), S.end(), 1);
    assert(ask(S) == 2);
}

void solveForTwo() {
    vector<bool> badNumber(n + 1);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> v = {i, j};
            int cur = ask(v);
            if (cur == 2) {
                return;
            }
            if (cur == 0) {
                badNumber[i] = badNumber[j] = true;
            }
        }
    }
    vector<int> S;
    for (int i = 1; i <= n; i++) {
        if (badNumber[i]) {
            continue;
        }
        S.emplace_back(i);
    }
    if (ask(S) == 2) {
        return;
    }
    int m = (int) S.size();
    for (int i = 0; i < m; i++) {
        vector<int> SS(m - 1);
        for (int j = 0, x = 0; j < m; j++) {
            if (j == i) {
                continue;
            }
            SS[x++] = S[j];
        }
        if (ask(SS) == 2) {
            return;
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str >> subsoal;
    cin >> n >> k >> q;
    if (subsoal == 5) {
        solveSubtaskFive();
    } else if (k == 1) {
        solveForOne();
    } else if (k == 2) {
        solveForTwo();
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;

int n;
string str;

pair<int, deque<char>> eraseRem(deque<char> s, int rem, bool two) {
    if ((int) s.size() == 1) return {INF, s};
    int last = -1;
    for (int i = 0; i < (int) s.size(); i++) {
        int num = (s[i] - '0');
        if (num % 3 == rem)
            last = i;
    }
    if (last == -1) return {INF, s};
    s.erase(s.begin() + last);
    int ret = 1;
    while ((int) s.size() > 1 && s.front() == '0') {
        s.pop_front();
        ++ret;
    }
    if (two) {
        pair<int, deque<char>> res = eraseRem(s, rem, false);
        res.first = min(INF, res.first + ret);
        return res;
    } else {
        return {ret, s};
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    deque<char> dq;
    dq.assign(str.begin(), str.end());
    int rem = 0;
    for (char CC : str) {
        int num = (CC - '0');
        rem = (rem + num) % 3;
    }
    if (rem == 0) {
        cout << str << '\n';
        return 0;
    }
    pair<int, deque<char>> ans = {INF, dq};
    ans = min(ans, eraseRem(dq, rem, false));
    ans = min(ans, eraseRem(dq, 3 - rem, true));
    if (ans.first == INF) {
        cout << -1 << '\n';
        return 0;
    }
    for (char CC : ans.second) {
        cout << CC;
    }
    cout << '\n';

    return 0;
}
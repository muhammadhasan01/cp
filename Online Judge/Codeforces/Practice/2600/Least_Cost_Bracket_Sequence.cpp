#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.length();
    int cur = 0;
    long long cost = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            int a, b;
            cin >> a >> b;
            s[i] = ')';
            cost += (1LL) * b;
            pq.push(make_pair(b - a, i));
            cur--; 
        } else if (s[i] == ')') {
            cur--;
        } else if (s[i] == '(') {
            cur++;
        }
        if (cur < 0) {
            if (pq.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            pair<int, int> temp = pq.top();
            pq.pop();
            cost -= (1LL) * temp.first;
            s[temp.second] = '(';
            cur += 2;
        }
    }
    if (cur) {
        cout << -1 << '\n';
    } else {
        cout << cost << '\n';
        cout << s << '\n';
    }

    return 0;
}
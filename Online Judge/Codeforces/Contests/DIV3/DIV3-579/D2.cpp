#include<bits/stdc++.h>
using namespace std;

string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    deque<int> pos, sop;
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == t[j]) {
            pos.push_back(i);
            j++;
            if (j == m) break;
        }
    }

    for (int i = n - 1, j = m - 1; i >= 0; i--) {
        if (s[i] == t[j]) {
            sop.push_front(i);
            j--;
            if (j < 0) break;
        }
    }

    int len = max(sop.front(), n - pos.back() - 1);

    for (int i = 0; i < m - 1; i++) {
        len = max(len, sop[i + 1] - pos[i] - 1);
    }

    cout << len << '\n';

    return 0;
}

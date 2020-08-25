#include <bits/stdc++.h>

using namespace std;

string a, b;

bool isSubsequence(const string& x, const string& y) {
    int need = y.size();
    int j = 0;
    for (int i = 0; i < (int) x.size(); i++) {
        if (x[i] == y[j]) {
            if (++j == need) return true;
        }
    }
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    if (isSubsequence(a, b)) {
        cout << b << '\n';
        return 0;
    }
    int n = a.size(), m = b.size();
    vector<int> pre(m + 2, n + 5), suf(m + 2, -5);
    pre[0] = -1;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (pos < m && a[i] == b[pos]) {
            pre[++pos] = i;
        }
    }
    pos = m - 1;
    suf[m + 1] = n;
    for (int i = n - 1; i >= 0; i--) {
        if (pos >= 0 && a[i] == b[pos]) {
            suf[pos + 1] = i;
            --pos;
        }
    }
    string answer = "";
    int maks = 0;
    int L = m, R = 0;
    for (int i = 0; i < m; i++) {
        int l = i + 1, r = m + 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (suf[mid] > pre[i]) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at == -1) continue;
        int curLen = i + (m - at + 1);
        if (curLen > maks) {
            maks = curLen;
            L = i, R = at - 1;
        }
    }
    if (L <= R) {
        for (int i = 0; i < L; i++)
            answer += b[i];
        for (int i = R; i < m; i++)
            answer += b[i];
    }
    if (answer.empty()) answer = "-";
    cout << answer << '\n';

    return 0;
}
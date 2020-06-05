#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

string s;
int cnt[30];
int st[N][30][30];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(12);
    cin >> s;
    int n = s.length();
    if (n == 1) {
        cout << 1.0 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int alf = s[0] - 'a';
        cnt[alf]++;
        for (int j = 1; j < n; j++) {
            int calf = s[j] - 'a';
            st[j][alf][calf]++;
        }
        char cur = s[0];
        s.erase(s.begin());
        s.push_back(cur);
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        int curres = 0;
        for (int d = 1; d < n; d++) {
            int curval = 0;
            for (int j = 0; j < 26; j++) {
                if (st[d][i][j] == 1) ++curval; 
            }
            curres = max(curres, curval);
        }
        res += curres;
    }
    cout << (long double) res / n << '\n';

    return 0;
}
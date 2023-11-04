#include <bits/stdc++.h>

using namespace std;

int n;
bool ok[30];
int match[30];
int p[30][2];

void dismiss() {
    cout << "NO" << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        vector<int> cnt(30);
        for (auto& e : s) {
            int alf = (e - 'a') + 1;
            ok[alf] = 1;
            if (++cnt[alf] == 2) dismiss();
        }
        int len = s.size();
        for (int it = 0; it < 2; it++) {
            for (int i = 0; i < len - 1; i++) {
                int id_1 = (s[i] - 'a') + 1;
                int id_2 = (s[i + 1] - 'a') + 1;
                if (p[id_1][it] == 0) {
                    p[id_1][it] = id_2;
                } else if (p[id_1][it] != id_2)
                    dismiss();
            }
            reverse(s.begin(), s.end());
        }
    }
    for (int i = 1; i <= 26; i++) {
        int cur = i;
        while (cur > 0) {
            if (match[cur] > 0) {
                if (match[cur] == i) dismiss();
                break;
            } else if (match[cur] == 0) {
                match[cur] = i;
            }
            cur = p[cur][0];
        }
    }
    for (int i = 1; i <= 26; i++) {
        if (!ok[i]) continue;
        if (p[i][1] > 0) continue;
        int x = i;
        while (x > 0) {
            cout << char(int('a') + x - 1);
            x = p[x][0];
        }
    }
    cout << '\n';

    return 0;
}
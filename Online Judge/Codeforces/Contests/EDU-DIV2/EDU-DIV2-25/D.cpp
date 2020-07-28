#include <bits/stdc++.h>

using namespace std;

const int K = 30;

string s[2];
long long len[2];
long long cnt[2][K];

bool can(long long x) {
    int cur = cnt[0][26];
    for (int it = 0; it < 26; it++) {
        if (cnt[1][it] * x <= cnt[0][it] + cur) {
            long long dif = max(0LL, cnt[1][it] * x - cnt[0][it]);
            cur = max(0LL, cur - dif);
        } else {
            return false;
        }
    }
    return true;
}

void get(long long x) {
    int cur = cnt[0][26];
    for (int it = 0; it < 26; it++) {
        if (cnt[1][it] * x <= cnt[0][it] + cur) {
            long long dif = max(0LL, cnt[1][it] * x - cnt[0][it]);
            cur = max(0LL, cur - dif);
            cnt[0][it] = dif;
        }
    }
    cnt[0][0] += cur;
    for (int i = 0; i < len[0]; i++) {
        if (s[0][i] == '?') {
            for (int j = 0; j < 26; j++) {
                if (cnt[0][j]) {
                    cout << char(int('a') + j);
                    cnt[0][j]--;
                    break;
                }
            }
        } else {
            cout << s[0][i];
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int it = 0; it < 2; it++) {
        cin >> s[it];
        len[it] = s[it].size();
        for (auto& e : s[it]) {
            if (e == '?') {
                cnt[it][26]++;
            } else {
                cnt[it][(int) (e - 'a')]++;
            }
        }
    }
    long long l = 0, r = len[0], ans = 0;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    get(ans);

    return 0;
}
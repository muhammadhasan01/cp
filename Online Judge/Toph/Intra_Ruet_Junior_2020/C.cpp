#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

string s;
int cnt[30];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    for (auto& e : s) {
        cnt[(int) (e - 'a')]++;
    }
    int n = s.length();
    int ans = INF;
    for (int i = 1; i <= 26; i++) {
        if (n % i != 0) continue;
        int need = n / i;
        vector<int> v(26, 0);
        for (int j = i; j < 26; j++)
            v[j] = 1;
        do {
            int small = 0, big = 0;
            for (int j = 0; j < 26; j++) {
                if (v[j]) continue;
                if (cnt[j] < need) small += need - cnt[j];
                else big += cnt[j] - need;
            }
            int mini = min(small, big);
            int cur = small + big - mini;
            ans = min(ans, cur);
        } while (next_permutation(v.begin(), v.end()));
    }
    cout << ans << '\n';

    return 0;
}
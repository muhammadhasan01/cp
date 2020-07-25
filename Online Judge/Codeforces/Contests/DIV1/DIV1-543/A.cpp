#include <bits/stdc++.h>

using namespace std;

const int M = 5e5 + 5;

int m, k, n, s;
int a[M];
int need[M];
int res, rem, cnt[M];

void add(int x) {
    if (++cnt[x] == need[x]) {
        ++res;
    }
}

void del(int x) {
    if (cnt[x]-- == need[x]) {
        --res;
    }
}

void get(int pos) {
    memset(cnt, 0, sizeof(cnt));
    vector<int> answer;
    for (int i = pos; i <= pos + k + rem - 1; i++) {
        if (++cnt[a[i]] > need[a[i]]) {
            answer.emplace_back(i);
        }
    }
    int len = min(rem, (int) answer.size());
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << answer[i] << (i == len - 1 ? '\n' : ' ');
    }
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m >> k >> n >> s;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    vector<int> val;
    for (int i = 1; i <= s; i++) {
        int x;
        cin >> x; need[x]++;
        val.emplace_back(x);
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    int uniq = val.size();
    rem = m - n * k;
    for (int i = 1; i <= k + rem; i++) {
        add(a[i]);
    }
    if (uniq == res) {
        get(1);
    }
    for (int i = k + 1; i <= n * k; i += k) {
        for (int j = i - k; j < i; j++) del(a[j]);
        for (int j = i + rem; j <= i + k + rem - 1; j++) add(a[j]);
        if (uniq == res)
            get(i);
    }
    cout << -1 << '\n';

    return 0;
}
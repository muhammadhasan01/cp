#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int INF = 2e9;

int n;
int k;
int a[N];
int cnt[N];
bool vis[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int mins = INF;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mins = min(mins, a[i]);
        cnt[a[i]]++;
    }
    for (int i = 1; i < N; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<int> divisor;
    for (int i = mins; i >= 1; i--) {
        if (mins % i <= k) divisor.push_back(i);
    }
    for (auto it : divisor) {
        int cur = 0;
        if (it <= k) {
            cout << it << '\n';
            return 0;
        }
        for (int i = it; i < N; i += it) {
            cur += (max(0, cnt[min(N - 1, i + k)] - cnt[i - 1]));
        }
        if (cur == n) {
            cout << it << '\n';
            return 0;
        }
    }

    return 0;
}
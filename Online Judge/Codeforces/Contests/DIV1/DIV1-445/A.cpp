#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int t[N];
int cnt[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int res = 1;
    for (int i = 0; i < N; i++) {
        res += max(0, cnt[i] - 1);
    }
    cout << res << '\n';
    
    return 0;
}
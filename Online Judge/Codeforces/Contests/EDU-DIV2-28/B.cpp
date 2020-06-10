#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n, k;
long long t[N];
long long m;
long long sum;

int get(int x) {
    long long res = 0;
    int ret = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n - x; j++) {
            res += t[i];
            if (res <= m) {
                ++ret;
            } else {
                return ret;
            }
        }
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++) {
        cin >> t[i];
        sum += t[i];
    }
    sort(t + 1, t + 1 + k);
    int answer = 0;
    for (int it = 0; it <= n; it++) {
        if (m < 0) break;
        int res = it * (k + 1) + get(it);
        answer = max(answer, res);
        m -= sum;
    }
    cout << answer << '\n';

    return 0;
}
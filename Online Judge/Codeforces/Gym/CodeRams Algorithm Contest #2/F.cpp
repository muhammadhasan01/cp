#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k;
int a[N];
int freq[N];
vector<int> divisors[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].emplace_back(i);
        }
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i < 3) {
            freq[a[i]]++;
            continue;
        }
        if (k % a[i] == 0) {
            int num = k / a[i];
            for (int x : divisors[num]) {
                int y = num / x;
                if (x > y) {
                    break;
                } else if (x < y) {
                    ans += 1LL * freq[x] * freq[y];
                } else if (x == y) {
                    ans += 1LL * freq[x] * (freq[x] - 1) / 2;
                }
            }
        }
        freq[a[i]]++;
    }
    cout << ans << '\n';

    return 0;
}
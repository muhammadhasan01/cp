#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
    }
    long long l = (sum - 1LL * n * (n - 1) / 2) / n + 1;
    sum = 1LL * l * n + 1LL * n * (n - 1) / 2 - sum;
    for (int i = 0; i < n; i++) {
        cout << l + i - (n - i <= sum) << " \n"[i == n - 1];
    }

    return 0;
}
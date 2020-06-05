#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, A, B;
long long s[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> A >> B;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        sum += s[i];
    }
    if (s[1] * A >= sum * B) {
        cout << 0 << '\n';
        return 0;
    }
    sort(s + 2, s + 1 + n, greater<int>());
    for (int i = 2; i <= n; i++) {
        sum -= s[i];
        if (s[1] * A >= sum * B) {
            cout << i - 1 << '\n';
            return 0;
        }
    }

    return 0;
}
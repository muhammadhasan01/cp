#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int K = 100;

long long pre[N];

int funny(int x) {
    int res = 0;
    while (x > 0) {
        int y = x % 10;
        res += y * y;
        x /= 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < N; i++) {
        int x = i;
        int res = INT_MAX;
        for (int j = 0; j < K; j++) {
            res = min(res, x);
            x = funny(x);
        }
        pre[i] = pre[i - 1] + res;
    }
    int A, B;
    cin >> A >> B;
    cout << pre[B] - pre[A - 1] << '\n';
    
    return 0;
}
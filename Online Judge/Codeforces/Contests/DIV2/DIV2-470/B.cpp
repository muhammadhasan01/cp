#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int x;
int prime[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prime[1] = 1;
    for (int i = 2; i <= N - 5; i++) {
        if (prime[i] == 0) {
            for (int j = i; j <= N - 5; j += i) {
                prime[j] = i;
            }
        }
    }

    cin >> x;
    int k = prime[x];
    int ans = N;
    for (int i = x; i >= x - k + 1; i--) {
        if (prime[i] == i) continue;
        ans = min(ans, i - prime[i]  + 1);
    }
    cout << ans << '\n';


    return 0;
}

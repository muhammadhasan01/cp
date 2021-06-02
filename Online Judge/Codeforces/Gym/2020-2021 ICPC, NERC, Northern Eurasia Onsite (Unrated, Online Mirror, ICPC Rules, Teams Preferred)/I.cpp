#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng32(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int N = 1e3 + 5;
const int K = 60;

int n, m;
int a[N];
int b[K], c[K];
char s[N];

long long getRand(long long x) {
    return ((unsigned long long) rng32() % x);
}

bool chooseMove(long long A, long long B) {
    return (getRand(A + B) >= A);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while (m--) {
        cin >> s;
        for (int i = 0; i < K; i++) {
            b[i] = c[i] = 0;
        }
        int mini = INF;
        for (int i = 0; i < n; i++) {
            mini = min(mini, a[i]);
        }
        for (int i = 0; i < n; i++) {
            int k = a[i] - mini;
            if (k >= K) continue;
            if (s[i] == '0')
                b[k]++;
            else
                c[k]++;
        }
        long long A = 0, B = 0;
        for (int k = 0; k < K / 2; k++) {
            A = A * 2 + b[k];
            B = B * 2 + c[k];
        }
        int move = chooseMove(A, B);
        cout << move << endl;
        cin >> move;
        for (int i = 0; i < n; i++) {
            a[i] += ((int) (s[i] - '0') != move);
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long INF = 1e18;

int n;
int p[N];
long long dif[N];
long long ans = INF;
int id;

void add(int l, int r, int val) {
    dif[l] += val;
    dif[r + 1] -= val;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        res += (1LL) * abs(p[i] - i);
        if (p[i] >= i) {
            add(2, i, 1);
            add(i + 1, i + 1, (n - p[i]) - (p[i] - 1));
            add(i + 2, i + 2 + (n - p[i]) - 1, -1);
            add(i + 2 + (n - p[i]), n, 1);
        } else {
            add(2, i - p[i] + 1, -1);
            add(i - p[i] + 2, i, 1);
            add(i + 1, i + 1, (n - p[i]) - (p[i] - 1));
            add(i + 2, n, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        dif[i] += dif[i - 1];
        res += dif[i];
        if (res < ans) {
            ans = res, id = n - i + 1;
            if (id == n) id = 0;
        }
    }
    cout << ans << " " << id << '\n';

    return 0;
}
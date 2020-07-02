#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 100;

int n, p;
int a[N];

bool can(int x, int i) {
    int len = min(n, n - (a[i] - x)) - (n - i);
    return (len < p);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int left_bound = 0;
    for (int i = 1; i <= n; i++) {
        left_bound = max(left_bound, a[i] - i + 1);
    }
    int right_bound = INF;
    for (int i = p; i <= n; i++) {
        int l = left_bound, r = INF, at = left_bound - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid, i)) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        right_bound = min(right_bound, at);
    }
    cout << right_bound - left_bound + 1 << '\n';
    for (int x = left_bound; x <= right_bound; x++) {
        cout << x << (x == right_bound ? '\n' : ' ');
    }

    return 0;
}
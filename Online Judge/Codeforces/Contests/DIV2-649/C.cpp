#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e6;

int n;
int a[N], b[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cur = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (a[i] == cur) {
            q.emplace(i);
        } else if (a[i] > cur) {
            b[i] = cur++;
            while (a[i] > cur) {
                b[q.front()] = cur++;
                q.pop();
            }
        }
    }
    while (!q.empty()) {
        b[q.front()] = INF;
        q.pop();
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
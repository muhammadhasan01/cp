#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int rep = 0; rep < 2 * n; rep++) {
        int s = n + 1, e = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                s = min(s, i);
                e = i;
            }
        }
        int pos = -1;
        for (int i = e; i >= s; i--) {
            if (a[i] == 0) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << rep << '\n';
            return;
        }
        swap(a[pos], a[e]);
    }
}

vector<int> getPrimes(int n) {
    int x = n;
    while ()
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> p(n + 1, -1);
    for (int i = 2; i <= n; i++) {
        if (p[i] != -1) {
            continue;
        }
        for (int j = i; j <= n; j += i) {
            p[j] = i;
        }
    }

    
    
    return 0;
}
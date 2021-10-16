#include <bits/stdc++.h>

using namespace std;

const int N = 13;

long long three[N], seven[N];
long long ten[N];

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ten[c] * three[a - c + 1] << ' ' << ten[c] * seven[b - c + 1] << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    {
        long long cur = 3;
        for (int i = 1; i < 20; i++) {
            int len = to_string(cur).size();
            if (len > 9) {
                break;
            }
            three[len] = cur;
            cur = cur * 3;
        }
    }
    {
        long long cur = 7;
        for (int i = 1; i < 20; i++) {
            int len = to_string(cur).size();
            if (len > 9) {
                break;
            }
            seven[len] = cur;
            cur = cur * 7;
        }
    }
    ten[1] = 1;
    for (int i = 2; i < N; i++) {
        ten[i] = ten[i - 1] * 10;
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}
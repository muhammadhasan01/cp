#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int M = 1e4 + 5;

int n;
string s;
int it = 0;
string prec[M];

void gen(string& v, int x, int y) {
    if (it == M) return;
    for (int i = 0; i < 26; i++) {
        char cc = char(int('a') + i);
        v.push_back(cc);
        if (x == y) {
            prec[it++] = v;
            if (it == M) return; 
        } else {
            gen(v, x + 1, y);
        }
        v.pop_back();
    }
}

void precompute() {
    for (int len = 1; len <= 1000; len++) {
        if (it == M) break;
        string cur = "";
        gen(cur, 1, len);
    }
}

void solve() {
    cin >> n >> s;
    for (int it = 0; it < M; it++) {
        int len = prec[it].size();
        bool flag = false;
        for (int j = 0; j < n - len + 1; j++) {
            if (s.substr(j, len) == prec[it]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << prec[it] << '\n';
            return;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute();
    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int B = 100;

int n;
long long b[N];
int h[N];
vector<int> hgh[B];

void dismiss() {
    cout << "No" << "\n";
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int it = 60; it >= 0; it--) {
            bool bit = (b[i] & 1LL << it);
            if (bit) {
                if (h[i] == 0) {
                    h[i] = it;
                    hgh[it].emplace_back(i);
                    break;
                }
            }
        }
    }
    bool flag
    for (int it = 60; it >= 0; it--) {
        int len = hgh[it].size();
        if (len == 0) continue;
        if (ff == -1) {
            ff = 
            if (len > 1) dismiss();
        }
    }

    return 0;
}
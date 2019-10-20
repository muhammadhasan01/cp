#include <bits/stdc++.h>

using namespace std;

const int N = 15;
int n;
pair<int, int> rook[N], tgt[N];
map<int, bool> avx, avy;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> rook[i].first >> rook[i].second;
        avx[root[i].first] = 1;
        avy[root[i].second] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> tgt[i].first >> tgt[i].second;
    }
    sort(rook + 1, rook + 1 + n);
    sort(tgt + 1, tgt + 1 + n);
    for (int i = 1; i <= n; i++) {
        while (rook[i].first != tgt[i].first) {
            if (rook[i].first > tgt[i].first) {
q
            } else if (rook[i].first < tgt[i].first) {

            }
        }
    }

    return 0;
}

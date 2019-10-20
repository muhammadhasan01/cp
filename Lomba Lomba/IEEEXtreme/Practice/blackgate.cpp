#include <bits/stdc++.h>
using namespace std;

const int N = 250 + 5;
int n;
vector<string> v[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string u; int k;
        cin >> u >> k;
        v[k].push_back(u);
    }
    int cl = 1, cr = 1;
    for (int i = 120; i <= 250; i++) {
        int len = v[i].size();
        if (!len) continue;
        sort(v[i].begin(), v[i].end());
        for (int j = 1; j <= len; j++) {
            cout << v[i][j - 1] << " ";
        }
        cr += len - 1;
        cout << cl << " " << cr << '\n';
        cl = ++cr;
    }

    return 0;
}

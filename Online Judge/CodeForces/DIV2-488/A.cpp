#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[15], b[15];
int cnt[15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        cnt[k] = 1;
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]] == 1) {
            ans.push_back(a[i]);
        }
    }

    for(auto e:ans) cout << e << " ";


    return 0;
}

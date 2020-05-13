#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n, k;
char a[N];
const string alf = "abcdefghijklmnopqrstuvwxyz";

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        vector<int> cnt(30);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[(int) (a[i] - 'a')]++;
        }
        vector<int> v;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                v.push_back(i);
            }
        }
        int len = v.size();
        if (cnt[v[0]] < k) {
            int pos = 0;
            for (int i = 0; i < len; i++) {
                k = max(0, k - cnt[v[i]]);
                if (k == 0) {
                    pos = v[i];
                    break;
                }
            }
            cout << alf[pos] << '\n';
        } else {
            vector<char> res;
            if (len == 1) {
                for (int j = 0; j < (cnt[v[0]] + k - 1) / k; j++) {
                    res.push_back(alf[v[0]]);
                }
            } else {
                if (len == 2 && cnt[v[0]] == k) {
                    res.push_back(alf[v[0]]);
                    for (int j = 0; j < (cnt[v[1]] + k - 1) / k; j++) {
                        res.push_back(alf[v[1]]);
                    }
                } else {
                    cnt[v[0]] -= (k - 1);
                    for (int i = 0; i < len; i++) {
                        for (int j = 0; j < cnt[v[i]]; j++) {
                            res.push_back(alf[v[i]]);
                        }
                    }
                }   
            }
            for (auto& e : res) cout << e;
            cout << '\n';
        }
    }

    return 0;
}
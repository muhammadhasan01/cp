#include <bits/stdc++.h>

using namespace std;

int tc;
int n, a, b;
string alf = "qwertyuiopasdfghjklzxcvbnm";

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b;
        vector<char> res(a);
        for (int i = 0; i < b - 1; i++) {
            res[i] = alf[i];
        }
        for (int i = b - 1; i < a; i++) {
            res[i] = alf[b - 1];
        }
        for (int i = 0; i < n; i++) {
            cout << res[i % a];
        }
        cout << '\n';
    }

    return 0;
}
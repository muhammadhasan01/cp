#include<bits/stdc++.h>
using namespace std;

int n;
string s;
bitset<15> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            for (int j = 0; j <= 9; j++) {
                if (vis[j] == 0) {
                    vis[j] = 1;
                    break;
                }
            }
        } else if (s[i] == 'R') {
            for (int j = 9; j >= 0; j--) {
                if (vis[j] == 0) {
                    vis[j] = 1;
                    break;
                }
            }
        } else {
            int x = s[i] - '0';
            vis[x] = 0;
        }
    }

    for(int i = 0; i <= 9; i++){
        cout << vis[i];
    }
    cout << '\n';


    return 0;
}

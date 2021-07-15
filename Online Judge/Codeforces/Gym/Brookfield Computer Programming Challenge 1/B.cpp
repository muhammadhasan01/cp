#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<string> str(2);
        for (int it = 0; it < 2; it++) {
            string tmp;
            for (int j = 0; j < 3; j++) cin >> tmp;
            cin >> str[it];
        }
        cout << "Uh! " << str[1] << "-" << str[0] << "!\n";
    }

    return 0;
}
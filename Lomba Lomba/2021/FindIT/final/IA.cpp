#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    for (int it = 0; it < q; it++) {
        string x;
        cin >> x;
        vector<vector<long long>> code(3, vector<long long>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> code[i][j];
            }
        }
        long long dur;
        cin >> dur;
        vector<long long> temp(10);
        for (int i = 0; i < 9; i++) {
            int cur = 0;
            if (isdigit(x[i])) {
                cur = (x[i] - '0') + 27;
            } else {
                cur = (tolower(x[i]) - 'a') + 1;
            }
            temp[i + 1] = cur;
        }
        vector<vector<long long>> temp_res(3, vector<long long>(3));
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << temp[++cnt] << " \n"[j == 2];
                temp_res[i][j] = temp[cnt];
            }
        }
        long long move = (dur / 4) % 4;
        vector<vector<long long>> res = code;
        if (move == 1) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    res[i][j] = code[2 - j][i];
                }
            }
        } else if (move == 2) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    res[i][j] = code[2 - i][2 - j];
                }
            }
        } else if (move == 3) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    res[i][j] = code[j][2 - i];
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << res[i][j] << " \n"[j == 2];
            }
        }
        vector<vector<long long>> mul(3, vector<long long>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    mul[i][j] += 1LL * temp_res[i][k] * res[k][j];
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << mul[i][j] << " \n"[j == 2];
            }
        }
        cout << '\n';
    }

    return 0;
}
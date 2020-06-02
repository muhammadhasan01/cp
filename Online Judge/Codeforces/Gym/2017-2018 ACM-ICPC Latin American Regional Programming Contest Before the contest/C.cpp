#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int k, n;
int cnt[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;
    int firstz = -1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        if (firstz == -1) firstz = x;
    }
    int onez = cnt[1];
    bool samez = true;
    for (int i = 1; i <= k; i++) {
        if (onez != cnt[i]) {
            samez = false;
            break;
        }
    }
    if (samez) {
        cout << "-" << firstz << " +" << firstz << '\n'; 
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        int res_1 = cnt[i] - 1;
        int res_2 = cnt[i] + 1;
        vector<int> id_1, id_2;
        bool fres_1 = true;
        bool fres_2 = true;
        int cnt_1 = 0, cnt_2 = 0;
        for (int j = 1; j <= k; j++) {
            if (i == j) continue;
            if (cnt[j] != res_1) {
                fres_1 = false;
            } else {
                cnt_1++;
            }
            if (cnt[j] != res_2) {
                fres_2 = false;
            } else {
                cnt_2++;
            }
            if (cnt[j] == cnt[i] - 2) {
                id_1.emplace_back(j);
            }
            if (cnt[j] == cnt[i] + 2) {
                id_2.emplace_back(j);
            }
        }
        if (fres_1) {
            cout << "-" << i << '\n';
            return 0;
        }
        if (fres_2) {
            cout << "+" << i << "\n";
            return 0;
        }
        if ((int) id_1.size() == 1 && (cnt_1 + 2) * res_1 == n) {
            cout << "-" << i << " +" << id_1[0] << '\n';
            return 0;
        }
        if ((int) id_2.size() == 1 && (cnt_2 + 2) * res_2 == n) {
            cout << "-" << id_2[0] << " +" << i << '\n';
            return 0;
        }
    }
    cout << "*" << '\n';

    return 0;
}
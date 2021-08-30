#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string n;
    cin >> n;
    int len = n.size();
    char maxi = n[0];
    for (char cc : n) {
        maxi = max(cc, maxi);
    }
    int k = maxi - '0';
    vector<string> results(k);
    for (int it = 0; it < k; it++) {
        results[it].assign(len, '0');
        for (int i = 0; i < len; i++) {
            if (n[i] == '0') {
                continue;
            }
            n[i]--;
            results[it][i] = '1';
        }
    }
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        int result = stoi(results[i]);
        cout << result << " \n"[i == k - 1];
    }
    
    return 0;
}
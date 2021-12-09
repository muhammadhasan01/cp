#include <bits/stdc++.h>

using namespace std;

const string WIN = "Make her kokoro go doki-doki!";
const string LOSE = "It is gonna be daijoubu.";
const int K = 26;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (char cc : str) {
            cnt[(int) (cc - 'a')]++;
        }
    }
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        for (char cc : str) {
            int num = (cc - 'a') + k;
            num = (num % K + K) % K;
            cnt[num]--;
        }
    }
    bool is_win = true;
    for (int i = 0; i < K; i++) {
        if (cnt[i] < 0) {
            is_win = false;
            break;
        }
    }
    cout << (is_win ? WIN : LOSE) << '\n';
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;



int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const string deck = "A23456789DQJK";
    const int K = deck.size();
    unordered_map<char, int> mp;
    for (int i = 0; i < K; i++) {
        mp[deck[i]] = i;
    }
    int n, k;   
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(K));
    vector<int> received(n, -1);
    int pos = --k;
    received[pos] = 0;
    int cur = k, tim = 0;
    auto debug = [&]() {
        cerr << "DEBUG STARTED\n";
        cerr << "Wildcard => " << pos + 1 << '\n';
        for (int i = 0; i < n; i++) {
            cerr << i + 1 << ": ";
            for (int j = 0; j < K; j++) {
                for (int x = 0; x < v[i][j]; x++)
                    cerr << deck[j];
            }
            cerr << '\n';
        }
        cerr << "DEBUG ENDED\n";
    };
    auto check = [&](int i) {
        if (i == pos)
            return;
        int inHand = 0;
        for (int j = 0; j < K; j++)
            inHand += v[i][j];
        if (inHand != 4)
            return;
        for (int j = 0; j < K; j++) {
            if (v[i][j] == 4) {
                cout << i + 1 << '\n';
                exit(0);
            }
        }
        return;
    };
    auto checker = [&]() {
        for (int i = 0; i < n; i++)
            check(i);
    };
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (char c : str) {
            v[i][mp[c]]++;
        }
    }
    while (1) {
        // debug();
        checker();
        if (pos == cur && received[pos] < tim) {
            received[(pos + 1) % n] = tim + 1;
            pos = (pos + 1) % n;
        } else {
            int mini = 5;
            for (int j = 0; j < K; j++) {
                if (v[cur][j] > 0)
                    mini = min(mini, v[cur][j]);
            }
            for (int j = 0; j < K; j++) {
                if (v[cur][j] == mini) {
                    v[cur][j]--;
                    v[(cur + 1) % n][j]++;
                    break;
                }
            }
        }
        // debug();
        cur = (cur + 1) % n, ++tim;
    }

    return 0;
}
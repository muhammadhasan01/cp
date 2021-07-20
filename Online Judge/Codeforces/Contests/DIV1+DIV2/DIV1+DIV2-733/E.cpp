#include <bits/stdc++.h>

using namespace std;

const int K = 26;

char get_alphabet(int x) {
    return char(x + int('a'));
}

void solve() {
    string str;
    cin >> str;
    int n = str.size();
    vector<int> freq(K);
    for (char cc : str) {
        freq[(int) (cc - 'a')]++;
    }
    auto output_remainders = [&]() -> void {
        for (int i = 0; i < K; i++) {
            if (freq[i] == 0) {
                continue;
            }
            for (int j = 0; j < freq[i]; j++) {
                cout << get_alphabet(i);
            }
        }
        cout << '\n';
    };
    int corner = -1;
    int fst = -1;
    for (int i = 0; i < K; i++) {
        if (freq[i] > 0) {
            if (fst == -1) {
                fst = i;
            }
        }
        if (freq[i] == 1) {
            corner = i;
            break;
        }
    }
    if (freq[fst] == 1 || freq[fst] == n) {
        sort(str.begin(), str.end());
        cout << str << '\n';
        return;
    }
    if (corner != -1) {
        cout << get_alphabet(corner);
        freq[corner]--;
        output_remainders();
        return;
    }
    int others = n - freq[fst];
    int len = (others + 1) * 2;
    // aa...
    if (len >= n) {
        int take = 1;
        for (int it = 0; it < take + 1; it++) {
            cout << get_alphabet(fst);
            freq[fst]--;
        }
        sort(str.begin(), str.end());
        for (char cc : str) {
            if (cc == get_alphabet(fst)) {
                continue;
            }
            cout << cc;
            for (int it = 0; it < take; it++) {
                if (freq[fst] == 0) {
                    break;
                }
                cout << get_alphabet(fst);
                freq[fst]--;
            }
        }
        cout << '\n';
        return;
    }
    
    // ab...
    int scn = -1, trd = -1;
    for (int i = fst + 1; i < K; i++) {
        if (freq[i] > 0) {
            if (scn == -1) {
                scn = i;
            } else if (trd == -1) {
                trd = i;
            }
        }
    }
    if (freq[scn] == 1) {
        cout << get_alphabet(fst);
        freq[fst]--;
        cout << get_alphabet(scn);
        freq[scn]--;
        output_remainders();
        return;
    }
    if (trd != -1) {
        cout << get_alphabet(fst);
        freq[fst]--;
        cout << get_alphabet(scn);
        freq[scn]--;
        for (int it = 0; it < freq[fst]; it++) {
            cout << get_alphabet(fst);
        }
        freq[fst] = 0;
        cout << get_alphabet(trd);
        freq[trd]--;
        output_remainders();
        return;
    }
    cout << get_alphabet(fst);
    freq[fst]--;
    for (int it = 0; it < freq[scn]; it++) {
        cout << get_alphabet(scn);
    }
    freq[scn] = 0;
    output_remainders();
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

struct TrieNode {
    int nxt[26];
    bool terminal;
    TrieNode() {
        fill(begin(nxt), end(nxt), -1);
        terminal = false;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int Q;
    cin >> Q;
    vector<TrieNode> trie;
    trie.reserve(N);
    trie.emplace_back();

    auto insertX = [&](const string &s) {
        int node = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (trie[node].nxt[idx] == -1) {
                trie[node].nxt[idx] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].nxt[idx];
        }
        trie[node].terminal = true;
    };

    auto isCovered = [&](const string &s) {
        int node = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (trie[node].nxt[idx] == -1) {
                return false;
            }
            node = trie[node].nxt[idx];
            if (trie[node].terminal) {
                return true;
            }
        }
        return false;
    };

    multiset<string> uncovered;
    long long cnt = 0;
    for (int q = 0; q < Q; q++) {
        int T;
        string S;
        cin >> T >> S;
        if (T == 1) {
            insertX(S);
            string low = S;
            string high = S;
            high.push_back('{');
            auto itL = uncovered.lower_bound(low);
            auto itR = uncovered.lower_bound(high);
            auto dist = distance(itL, itR);
            cnt -= dist;
            uncovered.erase(itL, itR);
        } else {
            if (!isCovered(S)) {
                uncovered.insert(S);
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}

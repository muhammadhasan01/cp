#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    int nxt[2];
    int idx;
    TrieNode() {
        nxt[0] = nxt[1] = -1;
        idx = -1;
    }
};

vector<TrieNode> trie;

void insertPrefix(int ip, int len, int id) {
    int node = 0;
    for (int i = 0; i < len; ++i) {
        int bit = (ip >> (31 - i)) & 1;
        if (trie[node].nxt[bit] == -1) {
            trie[node].nxt[bit] = trie.size();
            trie.emplace_back();
        }
        node = trie[node].nxt[bit];
    }
    trie[node].idx = id;
}

int queryIP(int ip) {
    int node = 0;
    int best = trie[0].idx;
    for (int i = 0; i < 32 && node != -1; ++i) {
        int bit = (ip >> (31 - i)) & 1;
        node = trie[node].nxt[bit];
        if (node != -1 && trie[node].idx != -1)
            best = trie[node].idx;
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    trie.reserve(n * 32 + 1);
    trie.emplace_back();

    auto parseIP = [](const string &s) {
        int a, b, c, d;
        char dot;
        stringstream ss(s);
        ss >> a >> dot >> b >> dot >> c >> dot >> d;
        return (a << 24) | (b << 16) | (c << 8) | d;
    };

    for (int i = 1; i <= n; i++) {
        string entry;
        cin >> entry;
        int slash = entry.find('/');
        int len = stoi(entry.substr(slash + 1));
        int ip = parseIP(entry.substr(0, slash));
        insertPrefix(ip, len, i);
    }

    for (int i = 0; i < m; i++) {
        string addr;
        cin >> addr;
        int ip = parseIP(addr);
        cout << queryIP(ip) << '\n';
    }

    return 0;
}
#include <memory>
#include <vector>

struct Trie {
    struct Node {
        vector<unique_ptr<Node>> child;
        int cnt;

        Node() : cnt(0), child(2, nullptr) {
        }
    };

    unique_ptr<Node> head;

    Trie() : head(make_unique<Node>()) {
    }

    void insert(int val) {
        Node* cur = head.get();
        for (int i = 30; i >= 0; --i) {
            bool v = val & (1 << i);
            ++cur->cnt;
            if (!cur->child[v]) {
                cur->child[v] = make_unique<Node>();
            }
            cur = cur->child[v].get();
        }
        ++cur->cnt;
    }

    void erase(int val) {
        Node* cur = head.get();
        for (int i = 30; i >= 0; --i) {
            bool v = val & (1 << i);
            --cur->cnt;
            cur = cur->child[v].get();
        }
        --cur->cnt;
    }

    int getMaxXOR(int val) {
        Node* cur = head.get();
        int res = 0;
        for (int i = 30; i >= 0; --i) {
            bool v = val & (1 << i);
            bool w = !v;
            if (cur->child[w] && cur->child[w]->cnt != 0) {
                cur = cur->child[w].get();
                res += (1 << i);
            } else {
                if (!cur->child[v]) {
                    cur->child[v] = make_unique<Node>();
                }
                cur = cur->child[v].get();
            }
        }
        return res;
    }

    int getMinXOR(int val) {
        Node* cur = head.get();
        int res = 0;
        for (int i = 30; i >= 0; --i) {
            bool v = val & (1 << i);
            if (cur->child[v] && cur->child[v]->cnt != 0) {
                cur = cur->child[v].get();
            } else {
                bool w = !v;
                if (!cur->child[w]) {
                    cur->child[w] = make_unique<Node>();
                }
                cur = cur->child[w].get();
                res += (1 << i);
            }
        }
        return res;
    }
};

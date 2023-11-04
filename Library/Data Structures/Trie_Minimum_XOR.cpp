// Inspiration from : https://codeforces.com/profile/yoganteng
struct Trie {
    struct Node {
        Node *child[2];
        int cnt;
        Node() {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };
 
    Node *head;
 
    Trie() {
        head = new Node();
    }
 
    void insert(int val) {
        Node *cur = head;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            ++cur->cnt;
            if (cur->child[v] == NULL) {
                cur->child[v] = new Node();
            }
            cur = cur->child[v];
        }
        ++cur->cnt;
    }
 
    void erase(int val) {
        Node *cur = head;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            --cur->cnt;
            cur = cur->child[v];
        }
        --cur->cnt;
    }
 
    int getMaxXOR(int val) {
        Node *cur = head;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            bool w = !v;
            if (cur->child[w] != NULL && cur->child[w]->cnt != 0) {
                cur = cur->child[w];
                res += (1 << i);
                continue;
            }
            if (cur->child[v] == NULL) {
                cur->child[v] = new Node();
            }
            cur = cur->child[v];
        }
        return res;
    }
 
    int getMinXOR(int val) {
        Node *cur = head;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            if (cur->child[v] != NULL && cur->child[v]->cnt != 0) {
                cur = cur->child[v];
                continue;
            }
            bool w = !v;
            if (cur->child[w] == NULL) {
                cur->child[w] = new Node();
            }
            cur = cur->child[w];
            res += (1 << i);
        }
        return res;
    }
};

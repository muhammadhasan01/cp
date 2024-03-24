struct Trie {
    struct Node {
        Node *child[26];
        int cnt;
        Node() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            cnt = 0;
        }
    };

    Node *head;

    Trie() {
        head = new Node();
    }

    void insert(string& val) {
        Node* cur = head;
        for (char& cc : val) {
            int x = cc - 'a';
            if (cur->child[x] == NULL) {
                cur->child[x] = new Node();
            }
            cur->cnt++;
            cur = cur->child[x];
        }
        cur->cnt++;
    }

    void erase(string& val) {
        Node* cur = head;
        for (char& cc : val) {
            int x = cc - 'a';
            cur->cnt--;
            cur = cur->child[x];
        }
        cur->cnt--;
    }
};
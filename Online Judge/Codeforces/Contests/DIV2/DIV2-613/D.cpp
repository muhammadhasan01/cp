#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = (1 << 30) - 1;

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
      ++cur -> cnt;
      if (cur -> child[v] == NULL) {
        cur -> child[v] = new Node();
      }
      cur = cur -> child[v];
    }
    ++cur -> cnt;
  }
  void erase(int val) {
    Node *cur = head;
    for (int i = 30; i >= 0; i--) {
      bool v = val & (1 << i);
      --cur -> cnt;
      cur = cur -> child[v];
    }
    --cur -> cnt;
  }
  int getMaxXOR(int val) {
    Node *cur = head;
    int ret = 0;
    for (int i = 30; i >= 0; i--) {
      bool v = !(val & (1 << i));
      if (cur -> child[v] != NULL && cur -> child[v] -> cnt != 0) {
        cur = cur -> child[v];
        ret += (1 << i);
      } else {
        cur = cur -> child[v ^ 1];
      }
    }
    return ret;
  }
};

int n;
int a[N];
Trie myTrie;
Trie tries[N];

bool can(int maks) {
  for (int i = 1; i <= n; i++) {
    int X = (a[i] ^ maks);
    int g = tries[i].getMaxXOR(X);
    if (g <= maks) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    myTrie.insert(a[i]);
  }
  if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  sort(a + 1, a + 1 + n, greater<int>());
  for (int i = 1; i <= n; i++) {
    myTrie.erase(a[i]);
    tries[i] = myTrie;
    myTrie.insert(a[i]);
  }
  int l = 0, r = INF, ans = INF;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';

  return 0;
}

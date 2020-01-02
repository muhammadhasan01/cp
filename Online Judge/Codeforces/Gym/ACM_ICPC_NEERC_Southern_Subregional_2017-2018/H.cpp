#include <bits/stdc++.h>

using namespace std;

int n;
string s;
map<char, int> m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  for (auto e : s) m[e]++;
  int odd = 0;
  vector<pair<char, int>> ev;
  vector<pair<char, int>> od;
  for (auto e : m) {
    if (e.second & 1) {
      odd++;
      od.push_back(e);
    } else {
      ev.push_back(e);
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    if (n % i == 0) {
      int part = n / i;
      if (part % 2 == 0 && odd == 0) {
        cout << i << '\n';
        int idx = 0;
        for (int j = 1; j <= i; j++) {
          string cur = "";
          int kk = part;
          while (kk > 0) {
            while (ev[idx].second == 0) idx++;
            cur.push_back(ev[idx].first);
            ev[idx].second -= 2;
            kk -= 2;
          }
          cout << cur;
          reverse(cur.begin(), cur.end());
          cout << cur;
          cout << (j == i ? '\n' : ' ');
        }
        return 0;
      } else if (part % 2 == 1 && odd <= i && (i - odd) % 2 == 0) {
        vector<char> middle(i + 3);
        for (int j = 1; j <= odd; j++) {
          middle[j] = od[j - 1].first;
          od[j - 1].second--;
        }
        for (auto e : od) if (e.second > 0) ev.push_back(e);
        priority_queue<pair<int, int>> pq;
        int len = ev.size();
        for (int j = 0; j < len; j++) {
          pq.push({ev[j].second, j});
        }
        int pos = odd + 1;
        while (pos <= i) {
          pair<int, int> curtop = pq.top();
          pq.pop();
          middle[pos] = middle[pos + 1] = ev[curtop.second].first;
          ev[curtop.second].second -= 2;
          pos += 2;
          curtop.first -= 2;
          if (curtop.first > 0) {
            pq.push(curtop);
          }
        }
        part--;
        cout << i << '\n';
        int idx = 0;
        for (int j = 1; j <= i; j++) {
          string cur = "";
          int kk = part;
          while (kk > 0) {
            while (ev[idx].second == 0) idx++;
            cur.push_back(ev[idx].first);
            ev[idx].second -= 2;
            kk -= 2;
          }
          cout << cur;
          reverse(cur.begin(), cur.end()); cout << middle[j];
          cout << cur;
          cout << (j == i ? '\n' : ' ');
        }
        return 0;
      }
    }
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << s[i] << (i == n - 1 ? '\n' : ' ');
  }

  return 0;
}

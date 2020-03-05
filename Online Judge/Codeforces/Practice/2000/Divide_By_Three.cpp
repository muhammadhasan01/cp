#include <bits/stdc++.h>

using namespace std;

string s;

bool erasez(string& x, int k) {
  if ((int) x.size() == 1) return false;
  for (int i = (int) x.size() - 1; i >= 0; i--) {
    int alf = (x[i] - '0') % 3;
    if (alf == k) {
      x.erase(x.begin() + i);
      return true;
    }
  }
  return false;
}

void no_leading(string &x) {
  while ((int) x.size() > 1 && x[0] == '0') {
    x.erase(x.begin());
  }
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  int sum = 0;
  for (auto e : s) {
    sum += (int) (e - '0');
  }
  string p = s, q = s;
  int rem = sum % 3;
  if (rem == 0) {
    cout << s << '\n';
    return 0;
  }
  int x = 2, y = 1;
  if (rem == 2) swap(x, y);
  if (erasez(p, y)) {
    if (erasez(q, x)) {
      if (erasez(q, x)) {
        no_leading(p);
        no_leading(q);
        if ((int) p.size() > (int) q.size()) {
          cout << p << '\n';
        } else {
          cout << q << '\n';
        }
        return 0;
      }
    }
    no_leading(p);
    cout << p << '\n';
    return 0;
  } else if (erasez(q, x)) {
    if (erasez(q, x)) {
      no_leading(q);
      cout << q << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';

  return 0;
}
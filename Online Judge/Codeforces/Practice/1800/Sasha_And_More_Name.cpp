#include <bits/stdc++.h>

using namespace std;

string s;
int n;

int get(int pos) {
  if (pos & 1) return 2;
  string left = s.substr(1, pos / 2);
  string right = s.substr(pos / 2 + 1, pos / 2);
  if (left != right) return 1;
  return get(pos / 2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  n = s.length();
  s = '#' + s + '#';
  set<char> st;
  for (int i = 1; i <= n / 2; i++) {
    st.insert(s[i]);
  }
  if ((int) st.size() <= 1) {
    cout << "Impossible" << '\n';
    return 0;
  }
  cout << get(n) << '\n';

  return 0;
}

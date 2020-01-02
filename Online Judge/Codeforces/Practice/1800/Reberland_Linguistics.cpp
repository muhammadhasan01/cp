#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
string s;
int n;
set<string> st;
bool dp[N][5];

void DP(int k, int t) {
  dp[k][t] = 1;
  if (k - 2 >= 6) {
    string s1 = s.substr(k, t);
    string s2 = s.substr(k - 2, 2);
    if (s1 != s2) {
      st.insert(s2);
      if (!dp[k - 2][2]) DP(k - 2, 2);
    }
    if (k - 3 >= 6) {
      string s3 = s.substr(k - 3, 3);
      if (s1 != s3) {
        st.insert(s3);
        if (!dp[k - 3][3]) DP(k - 3, 3);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  n = s.length();
  s = "#" + s + "#####";
  DP(n + 1, 2);
  cout << st.size() << '\n';
  for (auto e : st) {
    cout << e << '\n';
  }

  return 0;
}

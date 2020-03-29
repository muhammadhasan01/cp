#include <bits/stdc++.h>

using namespace std;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int res_1 = 0, res_2 = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int sz;
    cin >> sz;
    deque<int> dq(sz);
    for (int j = 0; j < sz; j++) {
      cin >> dq[j];
    }
    for (int j = 0; j < sz / 2; j++) {
      res_1 += dq.front();
      dq.pop_front();
    }
    for (int j = 0; j < sz / 2; j++) {
      res_2 += dq.back();
      dq.pop_back();
    }
    if (!dq.empty()) v.push_back(dq.front());
  }
  sort(v.begin(), v.end(), greater<int>());
  for (int i = 0; i < (int) v.size(); i++) {
    if (i % 2 == 0) {
      res_1 += v[i];
    } else {
      res_2 += v[i];
    }
  }
  cout << res_1 << " " << res_2 << '\n';

  return 0;
}
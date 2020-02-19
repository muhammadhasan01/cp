#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N], b[N];
long long dp[N];

struct line {
  double m, c;
  double get(double x) {
    return m * x + c;
  }
};

double interX(line a, line b) {
  return (b.c - a.c) / (a.m - b.m);
}

struct st {
  line l;
  int idx;
};

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <+ n; i++) {
    cin >> b[i];
  }
  deque<st> v;
  dp[1] = 0;
  v.push_back({{b[1], 0}, 1});
  for (int i = 2; i <= n; i++) {
    int cur = a[i];
    while ((int) v.size() >= 2 && v[0].l.get(cur) > v[1].l.get(cur)) v.pop_front();
    int j = v[0].idx;
    dp[i] = dp[j] + (1LL) * a[i] * b[j];
    line cur_line = {b[i], dp[i]};
    while ((int) v.size() >= 2 &&
      interX(cur_line, v.back().l) <= interX(v.back().l, v[(int) v.size() - 2].l)) v.pop_back();
    v.push_back({cur_line, i});
  }
  cout << dp[n] << '\n';

  return 0;
}
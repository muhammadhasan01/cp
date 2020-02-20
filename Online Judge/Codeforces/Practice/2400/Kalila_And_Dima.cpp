#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
 
int n;
int a[N], b[N];
long long dp[N];
 
struct line {
  long long m, c;
  long long get(long long x) {
    return m * x + c;
  }
};
 
double interX(line a, line b) {
  return (double) (b.c - a.c) / (double) (a.m - b.m);
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
  deque<line> v;
  dp[1] = 0;
  v.push_back({b[1], dp[1]});
  for (int i = 2; i <= n; i++) {
    long long cur = a[i];
    while ((int) v.size() >= 2 && v[0].get(cur) > v[1].get(cur)) v.pop_front();
    dp[i] = v[0].get(cur);
    line cur_line = {b[i], dp[i]};
    while ((int) v.size() >= 2 &&
      interX(cur_line, v.back()) <= interX(v.back(), v[(int) v.size() - 2])) v.pop_back();
    v.push_back(cur_line);
  }
  cout << dp[n] << '\n';
 
  return 0;
}
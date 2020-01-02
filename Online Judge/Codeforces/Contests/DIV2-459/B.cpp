#include <bits/stdc++.h>

using namespace std;

int n, m;
map<vector<int>, string> mp;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string temp, ip;
    cin >> temp >> ip;
    vector<int> v;
    int cur = 0;
    for (auto e : ip) {
      if (isdigit(e)) cur = 10 * cur + (e - '0');
      else {
        v.push_back(cur);
        cur = 0;
      }
    }
    v.push_back(cur);
    mp[v] = temp;
  }
  for (int i = 1; i <= m; i++) {
    string temp, ip;
    cin >> temp >> ip;
    vector<int> v;
    int cur = 0;
    for (auto e : ip) {
      if (isdigit(e)) cur = 10 * cur + (e - '0');
      else {
        v.push_back(cur);
        cur = 0;
      }
    }
    cout << temp << " " << ip << " #" << mp[v] << '\n';
  }

  return 0;
}

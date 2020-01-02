#include <bits/stdc++.h>

using namespace std;

struct st {
  int x, y, z;
};

int n;
vector<st> ans;
map<int, int> mp;
pair<int, int> p[3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }
  set<pair<int, int>> st;
  for (auto e : mp) {
    st.insert({-e.second, e.first});
  }
  while ((int) st.size() >= 3) {
    auto it = st.begin();
    for (int i = 0; i < 3; i++) {
      p[i] = {it -> second, it -> first};
      it++;
    }
    sort(p, p + 3);
    ans.push_back({p[2].first, p[1].first, p[0].first});
    for (int i = 0; i < 3; i++) {
      st.erase({p[i].second, p[i].first});
      if (p[i].second + 1 < 0) st.insert({p[i].second + 1, p[i].first});
    }
  }
  cout << ans.size() << '\n';
  for (auto e : ans) {
    cout << e.x << " " << e.y << " " << e.z << '\n';
  }

  return 0;
}

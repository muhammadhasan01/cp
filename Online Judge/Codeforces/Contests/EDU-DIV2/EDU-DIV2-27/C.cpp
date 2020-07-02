#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
pair<int, int> p[N];
int cnt[2 * N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        st.emplace(p[i].first);
        st.emplace(p[i].second);
    }
    unordered_map<int, int> mp;
    int ord = 0;
    for (auto& e : st) {
        mp[e] = ++ord;
    }
    for (int i = 1; i <= n; i++) {
        p[i].first = mp[p[i].first];
        p[i].second = mp[p[i].second];
        cnt[p[i].first]++;
        cnt[p[i].second + 1]--;
    }
    for (int i = 1; i < N; i++) {
        cnt[i] += cnt[i - 1];
        if (cnt[i] > 2) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';

    return 0;
}
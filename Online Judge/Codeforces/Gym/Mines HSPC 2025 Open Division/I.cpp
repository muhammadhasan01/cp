#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    map<string, pair<int, int>> coords;
    for (int i = 0; i < n; ++i) {
        string name;
        int x, y;
        cin >> name >> x >> y;
        coords.emplace(move(name), make_pair(x, y));
    }
    string prev_name;
    cin >> prev_name;
    auto [px, py] = coords[prev_name];
    long long total_dist = 0;
    for (int i = 1; i < n; ++i) {
        string cur_name;
        cin >> cur_name;
        auto [cx, cy] = coords[cur_name];
        total_dist += 1LL * (abs(cx - px)) + 1LL * (abs(cy - py));
        px = cx;
        py = cy;
    }
    cout << total_dist << "\n";
    
    return 0;
}
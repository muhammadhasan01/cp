#include <bits/stdc++.h>

using namespace std;

struct person {
    string name;
    int score, penalty;
    bool operator<(const person& other) {
        if (score == other.score)
            return penalty < other.penalty;
        return score > other.score;
    };
};

void solve() {
    int n;
    cin >> n;
    vector<person> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].score >> v[i].penalty;
    }
    sort(v.begin(), v.end());
    cout << v[0].name << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}
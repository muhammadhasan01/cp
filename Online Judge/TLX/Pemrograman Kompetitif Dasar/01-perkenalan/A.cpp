#include <bits/stdc++.h>

using namespace std;

struct participant {
    string id;
    int x, y, z;

    bool operator<(const participant& other) {
        if (z == other.z) {
            if (y == other.y) {
                return x > other.x;
            }
            return y > other.y;
        }
        return z > other.z;
    };
};

void solve() {
    int n, m;
    cin >> n >> m;
    string id;
    cin >> id;
    vector<participant> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].id >> p[i].s1 >> p[i].s2 >> p[i].s3;
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        if (p[i].id == id) {
            int rank = i + 1;
            cout << (rank <= m ? "YA" : "TIDAK") << '\n';
            return;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}
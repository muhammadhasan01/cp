#include <bits/stdc++.h>

using namespace std;

template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Vector dimension must be greater than zero!");
    template<typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) { }
};

template<typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, const T& val = T()) : vector<T>(n, val) { }
};

const int K = 105;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    Vec<3, int> a(K, K, K);
    for (int i = 1; i <= n; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                for (int z = z1; z < z2; z++) {
                    a[x][y][z] = i;
                }
            }
        }
    }
    vector<set<int>> ans(n + 1);
    for (int x = 0; x < K; x++) {
        for (int y = 0; y < K; y++) {
            for (int z = 0; z < K; z++) {
                if (a[x][y][z] == 0) {
                    continue;
                }
                if (a[x + 1][y][z] && a[x][y][z] != a[x + 1][y][z]) {
                    ans[a[x][y][z]].emplace(a[x + 1][y][z]);
                    ans[a[x + 1][y][z]].emplace(a[x][y][z]);
                }
                if (a[x][y + 1][z] && a[x][y][z] != a[x][y + 1][z]) {
                    ans[a[x][y][z]].emplace(a[x][y + 1][z]);
                    ans[a[x][y + 1][z]].emplace(a[x][y][z]);
                }
                if (a[x][y][z + 1] && a[x][y][z] != a[x][y][z + 1]) {
                    ans[a[x][y][z]].emplace(a[x][y][z + 1]);
                    ans[a[x][y][z + 1]].emplace(a[x][y][z]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (int) ans[i].size() << '\n';
    }
    
    return 0;
}
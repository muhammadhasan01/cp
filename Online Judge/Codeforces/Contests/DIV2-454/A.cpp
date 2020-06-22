#include <bits/stdc++.h>

using namespace std;

int v[4];
int len;

void generate(int x, vector<int> res) {
    if (x == 3) {
        if (v[3] > res.back()) return;
        if (res.back() <= len) {
            for (int i = 0; i < 2; i++) {
                if (res[i] <= len) return;
            }
            for (auto& e : res) {
                cout << e << '\n';
            }
            exit(0);
        }
        return;   
    }
    for (int i = v[x]; i <= 2 * v[x]; i++) {
        if (!res.empty() && res.back() <= i) return;
        res.push_back(i);
        generate(x + 1, res);
        res.pop_back();
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; i++) {
        cin >> v[i];
    }
    len = 2 * v[3];
    vector<int> temp;
    generate(0, temp);
    puts("-1");

    return 0;
}
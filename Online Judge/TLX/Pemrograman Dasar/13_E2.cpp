#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    auto getNearestTwo = [&](int x) -> int {
        int res = 1;
        while (res < x) {
            res = 2 * res;
        }
        return res;
    };
    
    int len;
    cin >> len;
    set<string> st;
    for (int i = 0; i < len; i++) {
        string s;
        cin >> s;
        st.emplace(s);
    }
    int r, c;
    cin >> r >> c;
    int p = getNearestTwo(max(r, c));
    vector<vector<int>> a(p, vector<int>(p));
    string cur = "1";

    function<void(int, int, int, int)> simulate = [&](int x1, int y1, int x2, int y2) {
        int len = (x2 - x1 + 1);
        assert(len == y2 - y1 + 1);
        if (st.find(cur) != st.end()) {
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    a[i][j] = 1;
                }
            }
            return;
        }
        if (len == 1) {
            return;
        }
        int sub = len / 2;
        cur += "0";
        simulate(x1, y1, x2 - sub, y2 - sub);
        cur.pop_back();

        cur += "1";
        simulate(x1, y1 + sub, x2 - sub, y2);
        cur.pop_back();
        
        cur += "2";
        simulate(x1 + sub, y1, x2, y2 - sub);
        cur.pop_back();
        
        cur += "3";
        simulate(x1 + sub, y1 + sub, x2, y2);
        cur.pop_back();  
    };
    
    simulate(0, 0, p - 1, p - 1);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " \n"[j == c - 1];
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int K = 26;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    auto getNum = [&](char cc) -> int {
        return cc - 'a';
    };
    
    auto askChar = [&](int i) -> char {
        cout << "? 1 " << i << endl;
        char ret;
        cin >> ret;
        return ret;
    };

    auto askQuery = [&](int l, int r) -> int {
        cout << "? 2 " << l << " " << r << endl;
        int ret;
        cin >> ret;
        return ret;
    };

    int n;
    cin >> n;
    vector<char> s(n + 1, '?');
    vector<int> last(K, -1);

    auto getQuery = [&](int l, int r) -> int {
        set<char> st;
        for (int i = l; i <= r; i++) {
            if (s[i] == '?') {
                continue;
            }
            st.emplace(s[i]);
        }
        return (int) st.size();
    };

    int numDistinct = 0;
    s[1] = askChar(1);
    last[getNum(s[1])] = 1;
    numDistinct++;
    for (int i = 2; i <= n; i++) {
        int cur = askQuery(1, i);
        if (cur > numDistinct) {
            numDistinct++;
            s[i] = askChar(i);
            last[getNum(s[i])] = i;
            continue;
        }
        vector<int> pos;
        for (int j = 0; j < K; j++) {
            if (last[j] == -1) {
                continue;
            }
            pos.emplace_back(last[j]);
        }
        sort(pos.begin(), pos.end());
        int len = (int) pos.size();
        int l = 0, r = len - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (askQuery(pos[mid], i) == getQuery(pos[mid], i)) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        assert(at != -1);
        s[i] = s[pos[at]];
        last[getNum(s[i])] = i;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << s[i];
    }
    cout << endl;
    
    return 0;
}
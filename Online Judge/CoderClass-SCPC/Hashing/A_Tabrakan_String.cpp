#include <bits/stdc++.h>

using namespace std;

const int K = 26;

int n;
long long M;
set<long long> st;

long long HASH(const string& s) {
    int len = s.size();
    long long cur = 1, ret = 0;
    for (int i = 0; i < len; i++) {
        long long add = ((long long) (s[i] - 'A') * cur) % M;
        ret = (ret + add) % M;
        cur = (cur * K) % M;
    }
    return ret;
}

void dismiss() {
    cout << "YA" << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        string str; cin >> str;
        long long res = HASH(str);
        if (st.find(res) != st.end()) dismiss();
        st.emplace(res);
    }
    cout << "TIDAK" << '\n';
    
    return 0;
}
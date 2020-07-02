#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, k;
char s[N];
int pre[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> (s + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') {
            st.emplace(i);
        } else {
            int pos = st.top();
            st.pop();
            pq.emplace(i - pos, pos);
        }
    }
    int len = n;
    vector<bool> vis(n + 1);
    while (!pq.empty() && len > k) {
        pii cur = pq.top();
        pq.pop();
        len -= 2;
        vis[cur.second] = true;
        vis[cur.second + cur.first] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        cout << s[i];
    }
    cout << '\n';

    return 0;
}
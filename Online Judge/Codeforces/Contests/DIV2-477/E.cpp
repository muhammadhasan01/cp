#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int B = 100;

int n;
long long b[N];
queue<long long> pq[B];

void dismiss() {
    cout << "No" << "\n";
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        cur = (cur ^ b[i]);
        for (int it = 60; it >= 0; it--) {
            bool bit = (b[i] & (1LL << it));
            if (bit) {
                pq[it].emplace(b[i]);
                break;
            }
        }
    }
    deque<long long> answer;
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        for (int j = 0; j <= 60; j++) {
            bool bit = (cur & (1LL << j));
            if (!bit) continue;
            if (pq[j].empty()) continue;
            long long temp = pq[j].front();
            pq[j].pop();
            answer.emplace_front(temp);
            cur = (cur ^ temp);
            flag = true;
            break;
        }
        if (!flag) dismiss();
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        cout << answer[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct skill {
    int a, b, idx;
};

const int N = 3e3 + 5;

int n, p, s;
skill person[N];
int col[N];

bool C1(const skill& x, const skill& y) {
    if (x.a == y.a)
        return x.b > y.b;
    return x.a > y.a;
}

bool C2(const skill& x, const skill& y) {
    if (x.b == y.b)
        return x.a > y.a;
    return x.b > y.b;
}

void solveOne() {
    sort(person + 1, person + 1 + n, C1);
    int ans = 0;
    for (int i = 1; i <= p; i++) {
        ans += person[i].a;
    }
    cout << ans << '\n';
    for (int i = 1; i <= p; i++) {
        cout << person[i].idx << (i == p ? '\n' : ' ');
    }
    cout << '\n';
    exit(0);
}

void solveTwo() {
    sort(person + 1, person + 1 + n, C2);
    int ans = 0;
    for (int i = 1; i <= s; i++) {
        ans += person[i].b;
    }
    cout << ans << '\n';
    cout << '\n';
    for (int i = 1; i <= s; i++) {
        cout << person[i].idx << (i == p ? '\n' : ' ');
    }
    exit(0);
}

int get(int pos) {
    int ret = 0;
    int x = pos - p;
    int y = s - x;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= pos; i++) {
        int cur = person[i].b - person[i].a;
        if ((int) pq.size() == x) {
            if (x > 0) {
                int tmp = pq.top();
                if (tmp < cur) {
                    ret += (cur - tmp);
                    pq.pop(); pq.emplace(cur);
                }
            }
        } else {
            pq.emplace(cur);
            ret += cur;
        }
        ret += person[i].a;
    }
    while (!pq.empty()) pq.pop();
    for (int i = pos + 1; i <= n; i++) {
        int cur = person[i].b;
        if ((int) pq.size() == y) {
            if (y > 0) {
                int tmp = pq.top();
                if (tmp < cur) {
                    ret += (cur - tmp);
                    pq.pop(); pq.emplace(cur);
                }
            }
        } else {
            pq.emplace(cur);
            ret += cur;
        }
    }
    return ret;
}

void answer(int pos) {
    int x = pos - p;
    int y = s - x;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= pos; i++) {
        int cur = person[i].b - person[i].a;
        if ((int) pq.size() == x) {
            if (x > 0) {
                auto e = pq.top();
                int tmp = e.first;
                if (tmp < cur) {
                    pq.pop(); pq.emplace(cur, person[i].idx);
                }
            }
        } else {
            pq.emplace(cur, person[i].idx);
        }
    }
    while (!pq.empty()) {
        auto tmp = pq.top(); pq.pop();
        col[tmp.second] = 2;
    }
    for (int i = 1; i <= pos; i++) {
        if (col[person[i].idx] == 2) continue;
        col[person[i].idx] = 1;
    }
    for (int i = pos + 1; i <= n; i++) {
        int cur = person[i].b;
        if ((int) pq.size() == y) {
            if (y > 0) {
                auto e = pq.top();
                int tmp = e.first;
                if (tmp < cur) {
                    pq.pop(); pq.emplace(cur, person[i].idx);
                }
            }
        } else {
            pq.emplace(cur, person[i].idx);
        }
    }
    while (!pq.empty()) {
        auto tmp = pq.top(); pq.pop();
        col[tmp.second] = 2;
    }
    vector<int> A, B;
    for (int i = 1; i <= n; i++) {
        if (col[person[i].idx] == 1) {
            A.emplace_back(person[i].idx);
        } else if (col[person[i].idx] == 2) {
            B.emplace_back(person[i].idx);
        }
    }
    for (int i = 0; i < p; i++) {
        cout << A[i] << (i == p - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < s; i++) {
        cout << B[i] << (i == s - 1 ? '\n' : ' ');
    }
}

void solve() {
    sort(person + 1, person + 1 + n, C1);
    int res = 0, pos = 0;
    for (int i = p; i <= p + s; i++) {
        int cur = get(i);
        if (cur > res) {
            res = cur, pos = i;
        }
    }
    cout << res << '\n';
    answer(pos);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> s;
    for (int i = 1; i <= n; i++) {
        cin >> person[i].a;
        person[i].idx = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> person[i].b;
    }
    if (p == 0) solveOne();
    if (s == 0) solveTwo();
    solve();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct DequeMin {
    deque<T> dq;

    bool isEmpty() {
        return dq.empty();
    }

    void add(T x) {
        while (!dq.empty() && dq.back() > x) {
            dq.pop_back();
        }
        dq.emplace_back(x);
    }

    void remove(T x) {
        if (dq.empty() || dq.front() != x) {
            return;
        }
        dq.pop_front();
    }

    T getMin() {
        return dq.front();
    }
};

template<typename T>
struct DequeMax {
    deque<T> dq;

    bool isEmpty() {
        return dq.empty();
    }

    void add(T x) {
        while (!dq.empty() && dq.back() < x) {
            dq.pop_back();
        }
        dq.emplace_back(x);
    }

    void remove(T x) {
        if (dq.empty() || dq.front() != x) {
            return;
        }
        dq.pop_front();
    }

    T getMax() {
        return dq.front();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    int m = n + n;
    vector<int> a(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }

    auto can = [&](int op) -> bool {
        int x = k - op;
        vector<int> cnt(n + 1);
        DequeMax<int> dqMax;
        DequeMin<int> dqMin;
        int numDuplicate = 0;
        for (int l = 0, r = -1; l < m - x + 1; l++) {
            while (r - l + 1 < x) {
                r++;
                dqMax.add(a[r]);
                dqMin.add(a[r]);
                if (++cnt[a[r]] == 2) {
                    numDuplicate++;
                }
            }
            if (numDuplicate == 0 && dqMax.getMax() - dqMin.getMin() <= k - 1) {
                return true;
            }
            if (--cnt[a[l]] == 1) {
                numDuplicate--;
            }
            dqMax.remove(a[l]);
            dqMin.remove(a[l]);
        }
        return false;
    };

    int ans = k - 1;
    int l = 0, r = k - 2;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
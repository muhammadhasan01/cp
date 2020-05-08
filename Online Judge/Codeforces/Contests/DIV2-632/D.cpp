#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;

int n, k;
bool a[N];
int res[N];
deque<int> idx;

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int maks = 0, mini = 0;
    int cnt = 0, last = -1;
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        a[i] = (x == 'R');
        if (!a[i]) {
            idx.push_back(i);
            maks += cnt;
            mini = max(cnt, last + 1);
            last = mini;
        } else {
            cnt++;
        }
    }
    if (k < mini || k > maks) dismiss();
    int cur = maks - k;
    for (int i = 1; i <= k; i++) {
        if (cur > 0) {
            int sz = idx.size();
            int len = 0;    
            for (int j = 0; j < sz; j++) {
                if (a[idx[j] - 1] && !a[idx[j]]) {
                    res[++len] = --idx[j];
                    if (len > 1 && --cur == 0) {
                        break;
                    }
                }
            }
            cout << len << ' ';
            for (int j = 1; j <= len; j++) {
                cout << res[j] << (j == len ? '\n' : ' ');
                swap(a[res[j]], a[res[j] + 1]);
            }
            while (!a[idx[0]] && a[idx[0]] == a[idx[0] - 1]) idx.pop_front();
        } else {
            while (!a[idx[0]] && a[idx[0]] == a[idx[0] - 1]) idx.pop_front();
            cout << 1 << " " << --idx[0] << '\n';
            swap(a[idx[0]], a[idx[0] + 1]);
        }
    }

    return 0;
}
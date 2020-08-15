#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 2e9;

int n;
pair<int, int> p[N];
long long bit[N][2];

void add(int x, int it, long long val) {
    for (int i = x; i <= n; i += i & -i) {
        bit[i][it] += val;
    }
}

long long get(int x, int it) {
    if (x == 0) return 0LL;
    long long ret = 0;
    for (int i = x; i > 0; i -= i & -i) {
        ret += bit[i][it];
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> vals;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        vals.emplace_back(abs(p[i].second));
    }
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    set<int> st;
    long long sum = 0;
    int numY = 0;
    int nums = 0;
    int smallestY = INF;
    int posY = -1;
    for (int i = 1; i <= n; i++) {
        int cur = abs(p[i].second);
        int pos = lower_bound(vals.begin(), vals.end(), cur) - vals.begin() + 1;
        sum += p[i].second;
        nums += (p[i].second > 0 ? 1 : -1);
        if (p[i].first == 0) {
            long long addz = (p[i].second > 0 ? 1 : -1);
            add(pos, 0, addz); add(pos, 1, p[i].second);
        } else if (p[i].first == 1) {
            if (p[i].second > 0) {
                numY++; st.emplace(p[i].second);
                if (numY == 1) {
                    smallestY = p[i].second;
                    posY = pos;
                } else if (numY > 1) {
                    if (p[i].second < smallestY) {
                        add(posY, 0, 1LL); add(posY, 1, smallestY);
                        smallestY = p[i].second; posY = pos;
                    } else {
                        add(pos, 0, 1LL); add(pos, 1, p[i].second);
                    }
                }
            } else {
                numY--; p[i].second = -p[i].second;
                st.erase(p[i].second);
                if (numY > 0) {
                    if (p[i].second == smallestY) { // find new smallest
                        smallestY = *st.begin();
                        posY = lower_bound(vals.begin(), vals.end(), smallestY) - vals.begin() + 1;
                        add(posY, 0, -1LL); add(posY, 1, -smallestY);
                    } else {
                        add(pos, 0, -1LL); add(pos, 1, -p[i].second);
                    }
                }
            }
        }
        long long addition = 0;
        if (numY > 0) {
            int l = 1, r = n, at = n;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (get(mid, 0) >= nums - numY) {
                    r = mid - 1;
                    at = mid;
                } else {
                    l = mid + 1;
                }
            }
            addition = get(n, 1) - get(at - 1, 1);
        }
        cout << sum + addition << '\n';
    }

    return 0;
}
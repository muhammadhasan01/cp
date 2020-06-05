#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int P = 2;
const int N = 3e5 + 5;

int n;
ll p[P];
pair<ll, int> c[N];
int pos[P][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p[0] >> p[1];
    for (int i = 1; i <= n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c + 1, c + 1 + n, greater<pair<ll, int>>());
    for (int it = 0; it < 2; it++) {
        for (long long k = 1; k < n; k++) {
            int l = 1, r = n, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (p[it] <= c[mid].first * k) {
                    at = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            pos[it][k] = at;
        }
    }
    for (int cur = 0; cur < 2; cur++) {
        int otr = 1 - cur;
        for (int k = 1; k < n; k++) {
            int curpos = pos[cur][k];
            if (curpos <= k) continue;
            int rem = curpos - k;
            int otrpos = pos[otr][rem];
            if (otrpos < rem) continue;
            vector<int> v1, v2;
            for (int i = 1; i <= k + rem; i++) {
                if (i <= rem) {
                    v2.push_back(c[i].second);
                    // assert(c[i].first * rem >= p[otr]);
                } else {
                    v1.push_back(c[i].second);
                    // assert(c[i].first * k >= p[cur]);
                }
            }
            if (cur == 1) v1.swap(v2);
            cout << "Yes" << '\n';
            int len1 = v1.size(), len2 = v2.size();
            cout << len1 << " " << len2 << '\n';
            for (int i = 0; i < len1; i++) {
                cout << v1[i] << (i == len1 - 1 ? '\n' : ' ');
            }
            for (int i = 0; i < len2; i++) {
                cout << v2[i] << (i == len2 - 1 ? '\n' : ' ');
            }
            return 0;
        }
    }
    cout << "No" << '\n';

    return 0;
}
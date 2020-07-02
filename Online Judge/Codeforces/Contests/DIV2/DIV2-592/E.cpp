#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long k;
int a[N];
map<int, long long> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    sort(a + 1, a + 1 + n);

    long long dif = a[n] - a[1];
    int i = 1, j = n;
    while (k > 0) {
        long long fi = m[a[i]];
        long long fj = m[a[j]];
        if (fi <= fj) {
            long long cur = a[i];
            while (i < j && cur == a[i]) i++;
            long long need = (a[i] - cur) * fi;
            if (need < k) {
                m[a[i]] += fi;
                m[cur] = 0;
                k -= need;
            } else {
                cur += k / fi;
                dif = a[j] - cur;
                break;
            }
        } else {
            long long cur = a[j];
            while (j > i && cur == a[j]) j--;
            long long need = (cur - a[j]) * fj;
            if (need < k) {
                m[a[j]] += fj;
                m[cur] = 0;
                k -= need;
            } else {
                cur -= k / fj;
                dif = cur - a[i];
                break;
            }
        }
        dif = a[j] - a[i];
        if (dif == 0) {
            break;
        }
    }
    cout << dif << '\n';

    return 0;
}

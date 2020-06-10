#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
const long long INF = 1e18;

int n;
int a[N];
long long suf;
long long res = INF;
int px, py, pz;

void upd(int pos) {
    long long ret = 0;
    long long sum = 0;
    int rx = 0, ry = 0, rz = pos;
    int li = 0;
    for (int i = 0; i < pos; i++) {
        sum += a[i];
        if (sum < ret) {
            ret = sum;
            rx = li;
            ry = i + 1;
        }
        if (sum > 0) {
            sum = 0;
            li = i + 1;
        }
    }
    ret += suf;
    if (ret < res) {
        res = ret;
        px = rx, py = ry, pz = rz;
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 0; i--) {
        suf += a[i];
        upd(i);
    }
    cout << px << " " << py << " " << pz << '\n';

    return 0;
}
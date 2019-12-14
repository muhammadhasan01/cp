#include <bits/stdc++.h>

using namespace std;

string s;
long long ev, od;
long long cntEv[2], cntOd[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    for (int i = 0; i < (int) s.size(); i++) {
        int pos = s[i] - 'a';
        od++;
        if (i % 2 == 0) {
            od += cntEv[pos];
            ev += cntOd[pos];
            cntEv[pos]++;
        } else {
            od += cntOd[pos];
            ev += cntEv[pos];
            cntOd[pos]++;
        }
    }
    cout << ev << " " << od << '\n';

    return 0;
}

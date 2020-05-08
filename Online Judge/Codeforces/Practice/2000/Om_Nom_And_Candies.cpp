#include <bits/stdc++.h>

using namespace std;

long long C, Hr, Hb, Wr, Wb;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> C >> Hr >> Hb >> Wr >> Wb;
    long long maks = 0;
    if (Wr * Wr >= C) {
        for (long long i = 0; i * Wr <= C; i++) {
            long long _C = C - i * Wr;
            long long j = (_C / Wb);
            maks = max(maks, i * Hr + j * Hb);
        }
    } else if (Wb * Wb >= C) {
        for (long long i = 0; i * Wb <= C; i++) {
            long long _C = C - i * Wb;
            long long j = (_C / Wr);
            maks = max(maks, i * Hb + j * Hr);
        }
    } else {
        if (Hb * Wr >= Wb * Hr) {
            swap(Hr, Hb);
            swap(Wr, Wb);
        }
        for (long long i = 0; i <= Wr; i++) {
            long long _C = C - i * Wb;
            long long j = (_C / Wr);
            maks = max(maks, i * Hb + j * Hr);
        }
    }
    cout << maks << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    string s;
    cin >> n >> s;

    // 1) Count total inversions D = # of (P before B) pairs
    ll D = 0;
    int pc = 0;
    for(char c: s){
        if(c=='P') {
            pc++;
        } else {
            D += pc;
        }
    }

    // 2) dpL[i][k]: in prefix s[0..i-1], maximum # of 2-inversion moves,
    //    with k = 0/1/2 representing how many B's in a row we've just ended on.
    vector<array<ll,3>> dpL(n+1, {0,0,0});
    for(int i = 1; i <= n; i++){
        dpL[i] = dpL[i-1];  // carry over
        if(s[i-1]=='B'){
            // we can extend a run of 1 B to 2 B's and do one more PBB move,
            // or extend any longer run.
            dpL[i][1] = max(dpL[i][1], dpL[i-1][0] + 1);
            dpL[i][2] = max({ dpL[i][2],
                              dpL[i-1][1] + 1,
                              dpL[i-1][2] + 1 });
        }
        // if it's a P, the run of B's is broken and we stay at dpL[i][0]
    }

    // 3) dpR[i][k]: same idea on the reversed string, but swap B<->P
    //    so that “PPB” at the end of the original suffix becomes “PBB”
    //    in the swapped version.
    vector<array<ll,3>> dpR(n+2, {0,0,0});
    for(int i = n; i >= 1; i--){
        dpR[i] = dpR[i+1];
        char c = (s[i-1]=='B' ? 'P' : 'B');
        if(c=='B'){
            dpR[i][1] = max(dpR[i][1], dpR[i+1][0] + 1);
            dpR[i][2] = max({ dpR[i][2],
                              dpR[i+1][1] + 1,
                              dpR[i+1][2] + 1 });
        }
    }

    // 4) Combine
    ll best2moves = 0;
    for(int i = 0; i <= n; i++){
        best2moves = max(best2moves, dpL[i][2] + dpR[i+1][2]);
    }

    // Answer = total inversions minus how many we can eliminate 2‑at‑a‑time
    cout << (D - best2moves) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}

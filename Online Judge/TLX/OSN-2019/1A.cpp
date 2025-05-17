#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    // Build a flat 2D prefix‐sum array P of size (R+1)×(C+1).
    vector<int> P((R+1)*(C+1), 0);
    long long K = 0;
    string row;
    for(int i = 1; i <= R; ++i){
        cin >> row;
        for(int j = 1; j <= C; ++j){
            int val = row[j-1] - '0';
            K += val;
            int idx = i*(C+1) + j;
            P[idx] = P[(i-1)*(C+1) + j]
                   + P[i*(C+1) + (j-1)]
                   - P[(i-1)*(C+1) + (j-1)]
                   + val;
        }
    }

    int maxInside = 0;
    bool possible = false;

    // Enumerate all factor pairs (h, w) of K
    for(int d = 1; (long long)d * d <= K; ++d){
        if(K % d != 0) continue;
        int h = d, w = K / d;

        // Try rectangle of height h, width w
        if(h <= R && w <= C){
            possible = true;
            for(int i = 1; i <= R - h + 1; ++i){
                int base1 = (i-1)*(C+1);
                int base2 = (i+h-1)*(C+1);
                for(int j = 1; j <= C - w + 1; ++j){
                    int j1 = j - 1, j2 = j + w - 1;
                    int sum = P[base2 + j2]
                            - P[base1 + j2]
                            - P[base2 + j1]
                            + P[base1 + j1];
                    maxInside = max(maxInside, sum);
                }
            }
        }

        // If h != w, also try the swapped orientation h↔w
        if(h != w){
            int hh = w, ww = h;
            if(hh <= R && ww <= C){
                possible = true;
                for(int i = 1; i <= R - hh + 1; ++i){
                    int base1 = (i-1)*(C+1);
                    int base2 = (i+hh-1)*(C+1);
                    for(int j = 1; j <= C - ww + 1; ++j){
                        int j1 = j - 1, j2 = j + ww - 1;
                        int sum = P[base2 + j2]
                                - P[base1 + j2]
                                - P[base2 + j1]
                                + P[base1 + j1];
                        maxInside = max(maxInside, sum);
                    }
                }
            }
        }
    }

    if(!possible){
        cout << -1 << "\n";
    } else {
        // Minimum moves = number of participants outside the best‐fitting K‐area rectangle
        cout << (K - maxInside) << "\n";
    }

    return 0;
}

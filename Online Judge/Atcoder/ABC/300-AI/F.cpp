#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    long long M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;
 
    // Build prefix sum for S:
    // A[i] = number of x's in S[0..i-1], for i = 0..N.
    vector<long long> A(N+1, 0);
    for (int i = 0; i < N; i++){
        A[i+1] = A[i] + (S[i]=='x');
    }
    long long X = A[N]; // total x's in one copy of S.
 
    // Answer: maximum contiguous block of o's (after flipping at most K x's).
    long long ans = 0;
    // For a starting position p (in copy 0) the maximum available length is:
    // avail = (N - p) + (M - 1)*N.
    for (int p = 0; p < N; p++){
        long long avail = (long long)(N - p) + (M - 1) * (long long)N;
        long long candidate = 0;
 
        // Number of x's in the tail of the first copy from p to end:
        long long tailX = A[N] - A[p];
        if(tailX > K){
            // We cannot take the whole tail.
            // Find max j in [p, N] such that A[j] - A[p] <= K.
            int lo = p, hi = N;
            while(lo < hi){
                int mid = (lo + hi + 1) / 2;
                if(A[mid] - A[p] <= K)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            candidate = lo - p;  // length within the same copy.
        } else {
            // We can take the whole tail from p.
            candidate = N - p;
            long long R = K - tailX;  // remaining x flips available.
 
            // Add as many full copies as possible.
            long long full = 0;
            if(X > 0) full = R / X;  // full copies we can add
            full = min(full, M - 1); // we cannot add more than M-1 full copies.
            candidate += full * (long long)N;
 
            // If there is still another copy available, try to extend partially.
            if(full < M - 1){
                long long rem = R - full * X; // remaining flips for the next copy.
                // In S, we want the maximum prefix with at most rem x's.
                // That is, find max j in [0, N] with A[j] <= rem.
                int lo = 0, hi = N;
                while(lo < hi){
                    int mid = (lo + hi + 1) / 2;
                    if(A[mid] <= rem)
                        lo = mid;
                    else
                        hi = mid - 1;
                }
                candidate += lo;
            }
        }
        candidate = min(candidate, avail);
        ans = max(ans, candidate);
    }
 
    cout << ans << "\n";
    return 0;
}

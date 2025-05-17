#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1'000'000'007;

// fast exponentiation
long long modexp(long long b, long long e){
    long long r=1%MOD;
    while(e){
        if(e&1) r = (r*b)%MOD;
        b = (b*b)%MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string label;
    cin >> label;             // test‐case label (ignored)
    int N, K;
    cin >> N >> K;

    vector<int> H(K+1);
    for(int j=1; j<=K; j++){
        cin >> H[j];
    }

    vector<int> A(N+1), B(N+1);
    for(int i=1; i<=N; i++){
        cin >> A[i];
    }
    for(int i=1; i<=N; i++){
        cin >> B[i];
    }

    // precompute factorials up to N+1
    vector<long long> fac(N+2), invfac(N+2);
    fac[0] = 1;
    for(int i=1; i<=N+1; i++){
        fac[i] = fac[i-1] * i % MOD;
    }
    // invfac[N+1] = (fac[N+1])^(MOD-2)
    invfac[N+1] = modexp(fac[N+1], MOD-2);
    for(int i=N; i>=0; i--){
        invfac[i] = invfac[i+1] * (i+1) % MOD;
    }

    // P(n,k) = n! / (n-k)!  if 0 <= k <= n, else 0
    auto P = [&](int n, int k){
        if(k<0 || k>n) return 0LL;
        return fac[n] * invfac[n-k] % MOD;
    };

    // counters per skywalk
    vector<int> L(K+1,0), E(K+1,0), R_(K+1,0);
    vector<int> M(K+1,0), F(K+1,0), U(K+1,0);

    // classify old‐floors
    for(int i=1; i<=N; i++){
        int j = A[i];
        if(i < H[j])        L[j]++;
        else if(i == H[j])  E[j]++;
        else                R_[j]++;
    }
    // classify new‐floors
    for(int p=1; p<=N; p++){
        int j = B[p];
        if(p < H[j])        M[j]++;
        else if(p == H[j])  F[j]++;
        else                U[j]++;
    }

    long long answer = 1;
    for(int j=1; j<=K; j++){
        int sumOld = L[j] + E[j] + R_[j];
        int sumNew = M[j] + F[j] + U[j];
        if(sumOld != sumNew){
            cout << 0 << '\n';
            return 0;
        }
        long long f = 0;
        if(F[j] == 0){
            // no "equal" in new
            f = P(M[j], R_[j]) * P(U[j], L[j]) % MOD;
        } else {
            // exactly one new‐equal cell
            // formula: P(M, R)*P(U+1, L)  +  R * P(M, R-1)*P(U, L)
            long long term1 = P(M[j], R_[j]) * P(U[j] + 1, L[j]) % MOD;
            long long term2 = (long long)R_[j]
                             * P(M[j], R_[j] - 1)
                             % MOD
                             * P(U[j], L[j])
                             % MOD;
            f = (term1 + term2) % MOD;
        }
        answer = answer * f % MOD;
    }

    cout << answer << '\n';
    return 0;
}

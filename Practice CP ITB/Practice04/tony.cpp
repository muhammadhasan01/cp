#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,X, k = 0, best= -1, S;
    cin >> N;
    if(N==1){
        cin >> X;
        cout << X << "\n";
        return 0;
    }
    ll a[N], b[N-1];
    cin >> a[0];
    X = a[0];
    for(ll i = 1; i < N; i++){
        cin >> a[i];
        b[i-1] = a[i]-X;
        best = max(best,b[i-1]);
        X = a[i];
    }
    S = best;
    for(ll i = 0; i < N-1; i++){
        if(b[i] == best){
            best--;
        }else if(b[i] > best){
            cout << S+1 << "\n";
            return 0;
        }
    }
    cout << S << "\n";
    return 0;
}

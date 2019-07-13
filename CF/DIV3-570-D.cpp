#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int q,n,a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> q;
    for(int nq=1;nq<=q;nq++){
        cin >> n;
        vector<int> f(n,0);
        for(int i=1;i<=n;i++){
            int x; cin >> x; f[x-1]++;
        }
        sort(f.begin(),f.end(),greater<int>());
        int start = f[0];
        int sum = start;
        for(int i=1;i<n;i++){
            start--;
            if(start > f[i])start = f[i];
            sum += max(0,start);
        }
        cout << sum << '\n';
    }

    return 0;
}

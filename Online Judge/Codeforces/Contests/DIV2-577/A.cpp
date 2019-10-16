#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int n,m;
string s[N];
int c[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    for(int i=1;i<=m;i++){
        cin >> c[i];
    }

    long long ans = 0;
    for(int i=1;i<=m;i++){
        vector<int> temp(6,0);
        for(int j=1;j<=n;j++){
            int x = s[j][i-1] - 'A';
            temp[x]++;
        }
        int maks = -1;
        for(auto e:temp)maks = max(maks, e);
        ans += (long long)maks * (long long)c[i];
    }
    cout << ans << '\n';

    return 0;
}

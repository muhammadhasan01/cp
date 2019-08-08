#include<bits/stdc++.h>
using namespace std;

int n,m;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s;
    vector<int> v(3*n);
    int len = 0, cnt = 0;
    for(int i=0;i<n;i+=2)if(s[i] != '1'){v[++len] = i+1; cnt++;}
    for(int i=0;i<n;i+=2)if(s[i] == '1')v[++len] = i+1;
    for(int i=1;i<n;i+=2)if(s[i] == '1')v[++len] = i+1;
    cout << len + cnt << "\n";
    for(int i=1;i<=len;i++)cout << 1 << " " << v[i] << "\n";
    for(int i=1;i<=cnt;i++)cout << 2 << " ";


    return 0;
}

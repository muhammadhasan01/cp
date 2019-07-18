#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a,b;cin>>a>>b;
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    int cek = b.size(), j=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[j]){
            j++;
        }
    }
    if(j==cek){cout << "YES\n";}else{cout<<"NO\n";}
    return 0;
}

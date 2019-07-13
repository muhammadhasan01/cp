#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    int a[N], first, second, sum = 0, total = 0;
    string f,s;
    for(int i=0;i<N;i++)cin>>a[i];
    cin >> first >> f;
    if(f=="right"){
        for(int i = first-1; i < N; i++){
            sum += a[i];
        }
    }else{
        for(int i = first-1; i >= 0; i--){
            sum += a[i];
        }
    }
    cin >> second >> s;
    if(s=="right"){
        for(int i = second-1; i < N; i++){
            if(a[i]==0)total++;
        }
    }else{
        for(int i = second-1; i >= 0; i--){
            if(a[i]==0)total++;
        }
    }
    cout << sum << " " << total << "\n";
    return 0;
}

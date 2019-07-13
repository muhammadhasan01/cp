#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool custom(string a, string b){
    string x = a+b, y = b+a;
    return x > y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    string a[N]; for(int i=0;i<N;i++)cin>>a[i];
    sort(a,a+N,custom);
    string jawab ="";
    for(int i=0;i<N;i++)jawab+=a[i];
    cout << jawab << "\n";
    return 0;
}

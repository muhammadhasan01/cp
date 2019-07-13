#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,r;
    cin >> a >> b >> r;
    if(2*r > min(a,b)){
        cout << "Irfan\n";
    }else{
        cout << "Iwang\n";
    }
    return 0;
}

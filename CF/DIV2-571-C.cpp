#include<bits/stdc++.h>
using namespace std;

string a,b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    int sa = (int)a.size(), sb = (int)b.size();
    int ba = (b[0] != a[0] ? 1 : 0), pre = 0, cur = 0;
    for(int i=0;i<sb;i++){
        if(i < sb-1 && b[i] != b[i+1])pre++;
        if(b[i] != a[i])cur++;
    }
    int ans = 0; cur %= 2; if(!cur)ans++;
    for(int i=sb;i<sa;i++){
        cur += ba + pre + (b[sb-1] != a[i] ? 1 : 0);
        ba = (b[0] != a[i-sb+1] ? 1 : 0);
        cur %= 2; if(!cur)ans++;
    }
    cout << ans << "\n";

    return 0;
}

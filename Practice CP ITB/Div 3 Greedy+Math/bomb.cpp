#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n==1){
        cout << "1 1\n";
        return 0;
    }
    sort(a,a+n);
    int ans = a[0], c1 = 1, c2 = 1, besar = -1;
    for(int i = 0; i < n-1; i++){
        if(a[i] == a[i+1]){
            c1++;
        }else{
            besar = max(besar,c1);
            c1 = 1;
            c2++;
        }
    }
    besar = max(besar,c1);
    cout << besar << " " << c2 << "\n";
    return 0;
}

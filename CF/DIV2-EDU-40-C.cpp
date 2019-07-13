#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
int a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    bool flag = true;
    int ans1 = 1e9, ans2 = 1e9;
    for(int i=1;i<n;i++){
        int dif = abs(a[i+1] - a[i]);
        if(dif > 1){
            if(ans2 == (int)1e9){
                ans2 = dif;
            }else if(ans2 != dif){
                puts("NO");
                return 0;
            }
        }else if(dif == 0){
            puts("NO");
            return 0;
        }
    }

    for(int i=1;i<=n;i++){
        int pos = (a[i] + ans2 - 1)/ans2;
        if(i > 1){
            int spos = (a[i-1] + ans2 - 1)/ans2;
            if(spos == pos && abs(a[i] - a[i-1]) != 1){
                puts("NO");
                return 0;
            }else if(spos != pos && abs(a[i] - a[i-1]) == 1){
                puts("NO");
                return 0;
            }
        }
    }

    cout << "YES" << '\n';
    cout << ans1 << " " << ans2 << '\n';

    return 0;
}

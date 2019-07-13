#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
pair<int,int> b[N];
bitset<N> pre, suf;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++)cin >> b[i].first, b[i].second = i;
    sort(b+1,b+1+n);
    if(n <= 3){
        puts("1");
        return 0;
    }
    int x = b[2].first - b[1].first;
    pre[1] = 1;
    for(int i=1;i<n;i++){
        if(b[i+1].first - b[i].first == x){
            pre[i+1] = 1;
        }else{
            break;
        }
    }
    int y = b[n].first - b[n-1].first;
    suf[n] = 1;
    for(int i=n;i>1;i--){
        if(b[i].first - b[i-1].first == y){
            suf[i-1] = 1;
        }else{
            break;
        }
    }

    if(suf[2]){
        cout << b[1].second << "\n";
        return 0;
    }

    if(pre[n-1]){
        cout << b[n].second << "\n";
        return 0;
    }

    for(int i=2;i<=n-1;i++){
        if(pre[i-1] && suf[i+1]){
            if(i <= n-2 && b[i+1].first - b[i-1].first == b[i+2].first - b[i+1].first){
                cout << b[i].second << "\n";
                return 0;
            }else if(i >= 3 && b[i+1].first - b[i-1].first == b[i-1].first - b[i-2].first){
                cout << b[i].second << "\n";
                return 0;
            }
        }
    }

    puts("-1");


    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
long long k;
long long a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);

    if(n == 1){
        cout << a[1] + k << '\n';
        return 0;
    }

    for(int i=1;i<=n;i++)cerr << a[i] << (i == n ? '\n' : ' ');

    int l = (n + 1)/2, r = (n + 1)/2 + 1;
    while(r <= n && k > 0){
        int len = r - l;
        if(a[r] > a[l]){
            long long dif = a[r] - a[l];
            if(k >= dif * len){
                a[l] = a[r];
                k -= dif * len;
            }else{
                a[l] += k/len;
                k = 0;
            }
        }else if(a[r] == a[l] && r < n){
            r++;
        }else if(a[r] == a[l] && r == n){
            a[l] += k/(len + 1);
            k = 0;
        }
    }
    cout << a[l] << '\n';

    return 0;
}

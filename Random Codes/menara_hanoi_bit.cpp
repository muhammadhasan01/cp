#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    reverse(a+1,a+1+n);
    vector<int> tail(n+3);
    tail[0] = a[1];
    int len = 1;
    for(int i=2;i<=n;i++){
        if(a[i] > tail[len-1]){
            tail[len++] = a[i];
        }else{
            if(binary_search(tail.begin(),tail.begin()+len,a[i]))continue;
            auto it = upper_bound(tail.begin(),tail.begin()+len,a[i]);
            *it = a[i];
        }
    }
    cout << len << '\n';

    return 0;
}

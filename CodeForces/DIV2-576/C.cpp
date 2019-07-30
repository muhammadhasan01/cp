#include<bits/stdc++.h>
using namespace std;

const int N = 4e5+5;
int n;
int a[N];
long long stg;
int pre[N], suf[N];
map<int,int> oc;

long long f(long long x){
    long long l = 0, r = 60, ret;
    while(l <= r){
        long long mid = (l+r)>>1;
        if(x <= (1<<mid)){
            r = mid - 1;
            ret = mid;
        }else{
            l = mid + 1;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> stg;
    stg *= 8;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        oc[a[i]]++;
    }
    int ans = n;
    sort(a+1,a+1+n);
    //for(int i=1;i<=n;i++){
    //    cerr << a[i] << " ";
    //}cerr << "\n";
    vector<int> v;
    v.push_back(-1);
    a[n+1] = -1;
    for(int i=1;i<=n;i++){
        if(a[i] != a[i+1]){
            v.push_back(a[i]);
        }
    }
    int len = v.size() - 1;

    //for(int i=1;i<=len;i++){
    //    cerr << v[i] << (i == len ? '\n' : ' ');
    //}

    for(int i=2;i<=len;i++){
        pre[i] = pre[i-1] + oc[v[i-1]];
        //cerr << i << " => " << pre[i] << '\n';
    }//cerr << '\n';
    for(int i=len-1;i>=1;i--){
        suf[i] = suf[i+1] + oc[v[i+1]];
        //cerr << i << " => " << suf[i] << '\n';
    }
    for(int i=1;i<=len;i++){
        int cur = pre[i];
        int l = i, r = len, pos = n;
        while(l <= r){
            int mid = (l + r)>>1;
            long long k = f(mid - i + 1);
            if(k * n <= stg){
                l = mid + 1;
                pos = cur + suf[mid];
            }else{
                r = mid - 1;
            }
        }
        ans = min(ans, pos);
    }
    cout << ans << '\n';

    return 0;
}

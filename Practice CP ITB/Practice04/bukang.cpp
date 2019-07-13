#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void tampung(vector<long long> a, long long len, set<long long, greater <long long> > &s, long long m){
    long long x = pow(2,len), temp, k;
    for(long long i = 0; i < x; i++){
        temp = 0;
        for(long long j = 0; j < len; j++){
            if(i & 1 << j){
                temp += a[j]%m;
            }
        }
        s.insert(temp%m);
    }
}

int main()
{
    long long n,m,temp;
    cin >> n >> m;
    vector<long long> v1,v2;
    for(long long i = 0; i < n; i++){
        cin >> temp;
        if(i < n/2){v1.push_back(temp%m);}else{v2.push_back(temp%m);}
    }
    long long maxi = -1;
    set<long long, greater <long long> > s1, s2;
    set<long long, greater <long long> >::iterator p;
    tampung(v1,v1.size(),s1,m);
    tampung(v2,v2.size(),s2,m);
    for(set<long long, greater <long long> >::iterator it = s1.begin(); it != s1.end(); it++){
            p = s2.lower_bound(m-*it-1);
            if(*p+*it >= m){p--;}
            maxi = max(maxi,*p+*it);
    }
    cout << maxi << "\n";
    return 0;
}

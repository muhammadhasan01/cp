#include<bits/stdc++.h>
using namespace std;

const int N = 30;
int n,q;
string s;
long long cnt[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> s;
    for(auto e:s)cnt[e - 'A']++;
    for(int i=1;i<=q;i++){
        char x;
        string y;
        cin >> x >> y;
        int temp = cnt[x - 'A'];
        for(auto e: y){
            cnt[e - 'A'] += temp;
        }
        cnt[x - 'A'] -= temp;
    }
    long long res = 0;
    for(int i=0;i<26;i++){
        res += cnt[i];
    }
    cout << res << '\n';

    return 0;
}

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

vector<LL> multiply(vector<LL> a, vector<LL> b) {
    vector<LL> v(a.size()+b.size()-1, 0);
    LL x = a.size()+b.size();
    for (LL i=0;i<a.size();i++) {
        for (LL j=0;j<b.size();j++) {
            v[i+j] += a[i]*b[j];
        }
    }
    // for (LL i=0;i<a.size();i++) cout << a[i] << " ";
    // cout << endl;
    // for (LL i=0;i<b.size();i++) cout << b[i] << " ";
    // cout << endl;
    // for (LL i=0;i<v.size();i++) cout << v[i] << " ";
    // cout << endl;
    // cout << "_+_+_++__+_" << endl;
    return v;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    vector<LL> ans;
    queue<vector<LL>> q;
    for (LL i=0;i<s.size()-1;i++) {
        if (s[i] != s[i+1]) {
            vector<LL> v;
            v.pb(1);
            v.pb(-2*i-3);
            q.push(v);
        }
    }
    while (q.size() > 1) {
        vector<LL> a = q.front();
        q.pop();
        vector<LL> b = q.front();
        q.pop();
        q.push(multiply(a,b));
    }
    if (q.empty() && s[0] == 'H') cout << 0 << endl << 1;
    else if (q.empty() && s[0] == 'A') cout << 0 << endl << -1;
    else {
        vector<LL> v = q.front();
        cout << v.size()-1 << endl;
        if (v.size()%2 == 1 && s[0] == 'A') {
            for (LL i=0;i<v.size();i++) v[i]*=-1;
        }
        if (v.size()%2 == 0 && s[0] == 'H') {
            for (LL i=0;i<v.size();i++) v[i]*=-1;
        }
        for (LL i=0;i<v.size();i++) cout << v[i] << " ";
    }
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

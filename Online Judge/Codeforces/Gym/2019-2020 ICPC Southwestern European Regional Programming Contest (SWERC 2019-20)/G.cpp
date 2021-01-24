#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int S, L, n;
map<string, int> getid;
string getname[N];
bool isadj[201][201];

vector<int> vec;
void pushtoback(int id){
    int len = vec.size();

    vector<int> nvec;
    vector<int> simp;
    for (int i=len - 1;i>=0;i--){
        if (vec[i] == id){
            nvec.pb(vec[i]);
        } else{
            if ((simp.size() || vec[i] <= id) && isadj[id][vec[i]]){
                simp.pb(vec[i]);
            } else{
                for (auto& x : simp){
                    nvec.pb(x);
                }
                simp.clear();
                nvec.pb(vec[i]);
            }
        }
    }
    for (auto& x : simp){
        nvec.pb(x);
    }
    reverse(nvec.begin(), nvec.end());
    vec.swap(nvec);
}
void solve(int id){
    for (int i=id + 1;i<=S;i++) if (isadj[id][i]) pushtoback(i);
    int len = vec.size();

    vector<int> nvec;
    vector<int> simp;
    for (int i=0;i<len;i++){
        if (vec[i] == id){
            nvec.pb(vec[i]);
        } else{
            if ((simp.size() || vec[i] >= id) && isadj[id][vec[i]]){
                simp.pb(vec[i]);
            } else{
                for (auto& x : simp){
                    nvec.pb(x);
                }
                simp.clear();
                nvec.pb(vec[i]);
            }
        }
    }
    for (auto& x : simp){
        nvec.pb(x);
    }
    vec.swap(nvec);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> L >> n;
    for (int i=1;i<=S;i++){
        string temp;
        cin >> temp;
        getid[temp] = 1;
    }    
    {
        int tempid = 0;
        for (auto& x : getid){
            x.se = ++tempid;
            getname[tempid] = x.fi;
        }
    }
    for (int i=1;i<=L;i++){
        string temp1, temp2;
        cin >> temp1 >> temp2;
        int id1 = getid[temp1];
        int id2 = getid[temp2];
        isadj[id1][id2] = 1;
        isadj[id2][id1] = 1;
    }
    for (int i=1;i<=n;i++){
        string temp;
        cin >> temp;
        vec.pb(getid[temp]);
    }
    for (int i=1;i<=S;i++){
        solve(i);
    }
    for (auto& x : vec){
        cout << getname[x] << " ";
    }
    cout << el;

    return 0;
}
// author : mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

vector <string> tar, vans;
// string line;
string cur = "";
int low = (int)'a', up = (int)'A';
int n, m;
bool upper;
int lentar, lenreal;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        string temp;
        cin >> temp;
        tar.pb(temp);
        lentar+=temp.length() + 1;
    }
    lentar--;
    // getline(cin, line);
    // cout << line << el;

    cin >> m;
    for (int i=0;i<m;i++){
        string inp;
        cin >> inp;
        if (inp[0]=='S'){
            cur.pb(' ');
            lenreal++;
        } else if (inp[0]=='C'){
            upper = !upper;
        } else if (inp[0]=='B'){
            if (!cur.empty()){
                cur.pop_back();
                lenreal--;
            }
        } else{
            int alpha = (int)inp[0] - low;
            char baru;
            if (upper){
                baru = (alpha + up);
            } else{
                baru = (alpha + low);
            }
            cur.pb(baru);
            lenreal++;
        }
    }

    stringstream ss(cur);
    string temp;
    while (ss >> temp){
        vans.pb(temp);
    }
    // cout << lentar << " " << lenreal << el;
    if (vans.size()!=tar.size() || lentar!=lenreal){
        cout << "Incorrect" << el;
        return 0;
    }

    // for (auto x : vans){
    //     cout << x << " ";
    // }cout << el;
    bool sama = 1;
    for (int i=0;i<n;i++){
        if (vans[i] != tar[i]){
            sama=0;
            break;
        }
    }
    if (sama){
        cout << "Correct" << el;
    } else{
        cout << "Incorrect" << el;
    }

    return 0;
}

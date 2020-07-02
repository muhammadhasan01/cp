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

const int N = 2e5 + 10;

int q;
int n, len;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        cin >> s;
        len = n-1;

        vector <int> ans1, ans2;
        int cur = 0;
        int sisa = n;
        for (int i=0;i<len;i++){
            // cout << i << el;
            int cnt1 = 1;
            for (int j=i+1;j<len;j++){
                if (s[i] == s[j]){
                    cnt1++;
                } else{
                    break;
                }
            }
            if (s[i] == '<'){
                int cnt2 = 0;
                for (int j=i+cnt1;j<len;j++){
                    if (s[i] != s[j]){
                        cnt2++;
                    } else{
                        break;
                    }
                }
                for (int j=0;j<cnt1 + cnt2 + 1;j++){
                    i++;
                    if (j < cnt1){
                        cur++;
                        ans1.pb(cur);
                    } else{
                        int plus = cnt1 + cnt2 + 1 - j;
                        ans1.pb(cur + plus);
                    }
                }
                cur += cnt2 + 1;
                i--;
            } else{
                vector <int> temp;
                for (int j=0;j<cnt1+1;j++){
                    cur++;
                    i++;
                    temp.pb(cur);
                }
                i--;
                // cout << i << el;
                reverse(temp.begin(), temp.end());
                for (auto x : temp){
                    ans1.pb(x);
                }
            }
        }
        if (ans1.size() < n){
            ans1.pb(cur+1);
        }

        cur = n+1;
        for (int i=0;i<len;i++){
            int cnt1 = 1;
            for (int j=i+1;j<len;j++){
                if (s[i] == s[j]){
                    cnt1++;
                } else{
                    break;
                }
            }
            if (s[i] == '>'){
                int cnt2 = 0;
                for (int j=i+cnt1;j<len;j++){
                    if (s[i] != s[j]){
                        cnt2++;
                    } else{
                        break;
                    }
                }
                for (int j=0;j<cnt1 + cnt2 + 1;j++){
                    i++;
                    if (j < cnt1){
                        cur--;
                        ans2.pb(cur);
                    } else{
                        int plus = cnt1 + cnt2 + 1 - j;
                        ans2.pb(cur - plus);
                    }
                }
                cur -= cnt2 + 1;
                i--;
            } else{
                vector <int> temp;
                for (int j=0;j<cnt1+1;j++){
                    cur--;
                    i++;
                    temp.pb(cur);
                }
                i--;
                reverse(temp.begin(), temp.end());
                for (auto x : temp){
                    ans2.pb(x);
                }
            }
        }
        if (ans2.size() < n){
            ans1.pb(cur-1);
        }

        for (auto x : ans2){
            cout << x << " ";
        }
        cout << el;
        for (auto x : ans1){
            cout << x << " ";
        }
        cout << el;
    }

    return 0;
}

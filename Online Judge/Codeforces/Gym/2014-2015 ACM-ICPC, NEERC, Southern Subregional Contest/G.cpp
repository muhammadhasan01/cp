// author: Mastre
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
const int INF = 1e9;

int n, k;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int mn = INF;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        mn = min(mn, ar[i]);
    }
    int l = 1, r = k;
    int cur = 0;
    int ans = 0;
    for (int i=1;i<=k;i++){
        cur += ar[i];
    }
    if (cur >= 0){
        for (int i=k;i>=1;i--){
            int kur = cur + 1;
            if (ar[i] - kur >= mn){
                ar[i] -= kur;
                cur -= kur;
                ans += kur;
                break;
            } else{
                ans += ar[i] - mn;
                cur -= ar[i] - mn;
                ar[i] = mn;
            }
        }
    }
    for (r=k + 1;r<=n;r++){
        cur -= ar[l];
        cur += ar[r];
        l++;
        if (cur >= 0){
            int kur = cur + 1;
            ar[r] -= kur;
            cur -= kur;
            ans += kur;
        }
    }
    cout << ans << el;
    for (int i=1;i<=n;i++){
        cout << ar[i] << " ";
    }
    cout << el;

    return 0;
}
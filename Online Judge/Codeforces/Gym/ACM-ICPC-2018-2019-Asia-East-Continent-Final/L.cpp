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

const int N = 1e5 + 7;

int n, m;
bool ar[N];
ll c1 = 0, c0 = 0;
ll sz[N];
// vector <int> v1, v0;
bool con0[N], con1[N];
ll ccnt0, ccnt1;
ll ada[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (ar[i]){
            c1++;
        } else{
            c0++;
        }
    }
    // c1 = v1.size();
    // c0 = v0.size();
    for (int i=1;i<=n;i++){
        if (ar[i]){
            sz[i] = c1 - 1;
        } else{
            sz[i] = c0 - 1;
        }
    }
    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        if (ar[a]!=ar[b]){
            ada[a]++;
            ada[b]++;
            if (ar[a]){
                if (!con1[a]){
                    con1[a]=1;
                    ccnt1++;
                }
            } else{
                if (!con0[a]){
                    con0[a]=1;
                    ccnt0++;
                }
            }

            if (ar[b]){
                if (!con1[b]){
                    con1[b]=1;
                    ccnt1++;
                }
            } else{
                if (!con0[b]){
                    con0[b]=1;
                    ccnt0++;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (ar[i]){
            if (ada[i]){
                sz[i] += ada[i] + 2 * (c0 - ada[i]);
            } else{
                sz[i] += 2 * ccnt0 + 3 * (c0 - ccnt0);
            }
        } else{
            if (ada[i]){
                sz[i] += ada[i] + 2 * (c1 - ada[i]);
            } else{
                sz[i] += 2 * ccnt1 + 3 * (c1 - ccnt1);
            }
        }
    }

    for (int i=1;i<=n;i++){
        cout << sz[i] << " ";
    }cout << el;

    return 0;
}

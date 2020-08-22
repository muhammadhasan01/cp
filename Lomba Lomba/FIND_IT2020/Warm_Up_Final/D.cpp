#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar('\n');
}

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

const int N = 1e5 + 10;

int n;
pair<ll, ll> ar[N];
priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    inpos(n);
    for (int i=1;i<=n;i++){
        inpos(ar[i].fi), inpos(ar[i].se);
    }

    sort(ar + 1, ar + n + 1);

    ll tot = 0, cur_time = 0;
    int id = 1;
    
    while (id <= n){
        if (pq.empty()){
            cur_time = max(cur_time, ar[id].fi);
            pq.push(mp(ar[id].se, ar[id].fi));
            id++;
        }

        while (id <= n && cur_time >= ar[id].fi){
            pq.push(mp(ar[id].se, ar[id].fi));
            id++;
        }

        auto it = pq.top();
        cur_time += it.fi;
        tot += cur_time - it.se;
        // cout << it.fi << " " << cur_time << el;
        pq.pop();
    }
    while (!pq.empty()){
        auto it = pq.top();
        cur_time += it.fi;
        tot += cur_time - it.se;
        // cout << it.fi << " " << cur_time << el;
        pq.pop();
    }

    long long res = tot / n;
    cout << res;

    return 0;
}
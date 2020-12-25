#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
 
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
 
#include <math.h>
#include <complex>
 
#include <assert.h>
#include <time.h>
#include <chrono>
#include <random>
 
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
 
#define F first
#define S second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
// #define endl '\n'
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N = 2e5;
ll arr[N + 5];
int id[N + 5];
int position[N + 5];

struct node{
    node *left, *right;
    int occurence;
    ll sum;
};

node *head[N + 5];

bool cmp(int a, int b) {
    return arr[a] < arr[b];
}

node *init() {
    node *cur = new node();
    cur->left = cur->right = cur; //create a self loop
    cur->occurence = 0;
    cur->sum = 0;
    return cur;
}

node *insert(node *pre, int l, int r, int tar, ll v) {
    node *cur = init();
    cur->left = pre->left, cur->right = pre->right;
    cur->occurence = pre->occurence + 1;
    cur->sum = pre->sum + v;
    if(l == r) return cur;
    int mid = (l + r) / 2;
    if(tar <= mid) cur->left = insert(pre->left, l, mid, tar, v);
    else cur->right = insert(pre->right, mid + 1, r, tar, v);
    return cur;
}

bool error = true;
ll total = 0, occ = 0;

void query(node *cur, node *pre, int l, int r, int le, int ri, ll avg) {
    if(le > ri) return ;
    if(r < le || ri < l) return ;
    if(le <= l && r <= ri) {
        ll node_sum = cur->sum - pre->sum;
        ll node_occ = cur->occurence - pre->occurence;
        if((total + node_sum) >= avg * (occ + node_occ)) { //the average is still bigger than avg, can get this whole node
            total += node_sum;
            occ += node_occ;
            return ;
        }
        //we cannot get this whole node. So try to traverse the tree
        int mid = (l + r) / 2;
        query(cur->right, pre->right, mid + 1, r, le, ri, avg); //try to get bigger number first
        if(error == false) { //we can try to traverse to the left
            query(cur->left, pre->left, l, mid, le, ri, avg);
        }
        error = true;
        return ;
    }
    int mid = (l + r) / 2;
    query(cur->right, pre->right, mid + 1, r, le, ri, avg); //try to get bigger number first
    if(error == false) { //we can try to traverse to the left
        query(cur->left, pre->left, l, mid, le, ri, avg);
    }
    return ;
}

int main() {
    desperate_optimization(10);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>arr[i];
        id[i] = i;
    }

    //rerank the array value
    sort(id + 1, id + n + 1, cmp);
    for(int i = 1;i <= n;i++) position[id[i]] = i;

    head[0] = init();

    for(int i = 1;i <= n;i++) head[i] = insert(head[i - 1], 1, n, position[i], arr[i]);

    int q;
    cin>>q;
    while(q--) {
        ll L, R, A, B, avg;
        cin>>L>>R;
        cin>>B>>A>>avg;
        int lo = 1;
        int hi = n;
        int start = n + 1;
        //finding lower bound index
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[id[mid]] >= B) {
                start = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }

        lo = 1, hi = n;
        int end = 0;
        //finding upper bound index
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[id[mid]] <= A) {
                end = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        // cout<<"AT "<<L<<" "<<R<<" "<<start<<" "<<end<<endl;
        error = false, total = occ = 0;
        query(head[R], head[L - 1], 1, n, start, end, avg);
        cout<<occ<<endl;
    }
}
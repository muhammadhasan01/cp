#include<bits/stdc++.h>
using namespace std;

struct st{
    long long v; int h;
};

int n,m,k;
vector<st> tree;

void build(){
    for(int i=k-1; i > 0; i--){
        //cout << i << "\n";
        if(tree[2*i].h & 1){
            tree[i].v = tree[2*i].v|tree[2*i+1].v;
            tree[i].h = tree[2*i].h+1;
            //cout << i << " => " << tree[i].v << " => " << tree[2*i].v << " |\n";
        }else{
            tree[i].v = tree[2*i].v^tree[2*i+1].v;
            tree[i].h = tree[2*i].h+1;
            //cout << i << " => " << tree[i].v << " => " << tree[2*i].v << " ^\n";
        }
    }
}

long long update(int p, long long val){
    for(tree[p+=k].v = val; p>1; p/=2){
        //cout << p/2 << "\n";
        if(tree[p].h&1){
            tree[p/2].v = tree[p].v|tree[p^1].v;
        }else{
            tree[p/2].v = tree[p].v^tree[p^1].v;
        }
    }
    //cout << "\n";
    return tree[1].v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    k = pow(2,n);
    tree.resize(2*k);
    for(int i=0;i<k;i++){
        cin >> tree[k+i].v;
        tree[k+i].h = 1;
    }
    build();
    while(m--){
        int p; long long val;
        cin >> p >> val;
        cout << update(p-1,val) << "\n";
    }
    return 0;
}

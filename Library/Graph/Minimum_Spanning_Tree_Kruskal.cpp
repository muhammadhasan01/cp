#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// source : https://github.com/morsalins/Algorithms-and-Data-Structures/blob/master/Minimum%20Spanning%20Tree/Kruskal%20MST%20(using%20STL).cpp

struct E{
    int u,v,w;
};

const int N = 100;
int T,n,m,a,b,c;
E temp;
vector<E> graph; // Store the inputted graph (u, v, w).
vector<E> selected_edges; // Store the edges which is selected for the MST from given graph.
int parent[N+2];

bool cstm(E a, E b){
    return a.w < b.w;
}

int findParent(int r){
    if(r == parent[r])return r;
    return parent[r] = findParent(parent[r]);
}

int Kruskal_MST(){

    for(int i=1;i<=n;i++)parent[i] = i;

    sort(graph.begin(),graph.end(),cstm);

    /*for(int i=0;i<graph.size();i++){
        cout << graph[i].w << "\n";
    }*/

    int edgeCounter = 0, totalCost = 0;

    int len = graph.size();

    for(int i=0; i<len;i++){

        int parent_of_u = findParent(graph[i].u);
        int parent_of_v = findParent(graph[i].v);

        if(parent_of_u != parent_of_v){
            parent[parent_of_u] = parent_of_v;
            totalCost += graph[i].w;
            selected_edges.pb(graph[i]);

            edgeCounter++;
            if(edgeCounter == n-1)
                break;
        }

    }
    return totalCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a >> b >> c;
        temp.u = a, temp.v = b, temp.w = c;
        graph.pb(temp);
    }

    cout << Kruskal_MST() << "\n";

    return 0;
}

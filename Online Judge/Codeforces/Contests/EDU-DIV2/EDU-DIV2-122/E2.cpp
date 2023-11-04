#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<int>T;
ll f[100000];
int d[100000];
int n,m;
int u[303],v[303],w[303];
int fa[53];
int Fa(int x){
	return fa[x]==x?x:fa[x]=Fa(fa[x]);
}
ll ask(int w){
	int pos=upper_bound(T.begin(),T.end(),w)-T.begin()-1;
	return f[pos]+(ll)(w-T[pos])*d[pos];
}
int main(){
	scanf("%d%d",&n,&m),T.push_back(0);
	for(int i=0;i<m;i++)scanf("%d%d%d",&u[i],&v[i],&w[i]),T.push_back(w[i]);
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)if(w[i]<w[j]){
		int md=(w[i]+w[j])/2;
		T.push_back(md),T.push_back(md+1);
	}
	sort(T.begin(),T.end()),T.erase(unique(T.begin(),T.end()),T.end());
	for(int p=0;p<T.size();p++){
		int t=T[p];
		vector<pii>E;
		for(int i=0;i<m;i++)E.push_back({abs(t-w[i]),i});
		for(int i=1;i<=n;i++)fa[i]=i;
		sort(E.begin(),E.end());
		int cnt=0;
		for(int i=0;i<m;i++){
			int id=E[i].se;
			int U=Fa(u[id]),V=Fa(v[id]);
			if(U==V)continue;
			cnt++;
			f[p]+=E[i].fi;
			int W=w[id];
			d[p]+=t>=W?1:-1;
			fa[U]=V;
			if(cnt==n-1)break;
		}
	}
	ll ans=0;
	int q,k,a,b,c,z;scanf("%d%d%d%d%d",&q,&k,&a,&b,&c);
	for(int i=1;i<=q;i++)scanf("%d",&z),ans^=ask(z);
	for(int i=q+1;i<=k;i++)z=((ll)z*a+b)%c,ans^=ask(z);
	printf("%lld",ans);
}
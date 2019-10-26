// https://www.qingtingip.com/h_241110.html
#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int T;
int n,m;
int a[maxn][maxn],sum[maxn][maxn];
bool check(int x,int y,int r)
{
 return sum[x+r-1][y+r-1]-sum[x-1][y+r-1]-sum[x+r-1][y-1]+sum[x-1][y-1]<=1;
}
int solve(int x,int y)
{
 int l=0,r=min(n-x+1,m-y+1),ans=0;
 while(l<=r)
 {
     int mid=(l+r)>>1;
     if(check(x,y,mid))ans=mid,l=mid+1;
     else r=mid-1;
 }
 return ans;
}
struct FastIO
{
 static const int S=5<<20;
 int wpos;char wbuf[S];
 FastIO():wpos(0){}
 inline int xchar()
 {
     static char buf[S];
     static int len=0,pos=0;
     if(pos==len)pos=0,len=fread(buf,1,S,stdin);
     if(pos==len)return -1;
     return buf[pos++];
 }
 inline int xuint()
 {
     int c=xchar(),x=0;
    while(~c&&c<=32)c=xchar();
   for(;'0'<=c&&c<='9';c=xchar())x=x*10+c-'0';
     return x;
 }
}io;
int main()
{
 T=io.xuint();
 while(T--)
 {
     n=io.xuint();m=io.xuint();
     for(int i=1;i<=n;++i)
         for(int j=1;j<=m;++j)a[i][j]=io.xuint();
     for(int i=1;i<=n;++i)
         for(int j=1;j<=m;++j)sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
     int ans=0;
     for(int i=1;i<=n;++i)
         for(int j=1;j<=m;++j)
         {
            ans=max(ans,solve(i,j));
         }
     printf("%d\n",ans);
 }
}

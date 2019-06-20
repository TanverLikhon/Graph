/*Never Give up*/
/*
Problem  :https://codeforces.com/contest/330/problem/B
Verdict     :AC
Time         :60ms
Memory  :300KB
*/
#include<bits/stdc++.h>
using namespace std;
#define sf(a)          scanf("%d",&a)
#define sff(a,b)         scanf("%d%d",&a,&b)
#define sfff(a,b,c)         scanf("%d%d%d",&a,&b,&c)
#define sffff(a,b,c,d)         scanf("%d%d%d%d",&a,&b,&c,&d)
#define sl(a)          scanf("%lld",&a)
#define sll(a,b)         scanf("%lld%lld",&a,&b)
#define slll(a,b,c)         scanf("%lld%lld%lld",&a,&b,&c)
#define sllll(a,b,c,d)         scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define sc(a) scanf("%c",&a)
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define vi           vector<int>
#define vl           vector<ll>
#define li            list<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define mp         map
#define nl         printf("\n")
#define en        pf("Ente1d\n")
#define en1      pf("Enter1d\n")
#define MAX    1005
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
mp<pi,bool>c;
bool visited[MAX];
bool visited1[MAX];
int src;
int n,m;
void graph()
{
  queue<int>q;
  q.push(src);
  visited[src]=true;
  while(!q.empty())
  {
    int x=q.front();q.pop();
    for(int i=1;i<=n;i++)
    {
      if(i!=x&&!visited[i]&&c[{i,x}]==false&&c[{x,i}]==false)
      {
         //cout<<x<<" "<<i<<endl;
         pf("%d %d\n",x,i);
         visited[i]=true;q.push(i);
      }
       //   edge[x].pb(i),visited[i]=true,q.push(i);
    }

  }
}
int main()
{
 sff(n,m);
 while(m--)
 {
   int a,b;
   sff(a,b);
   c[{a,b}]=true;
   c[{b,a}]=true;
   visited1[a]=true,visited1[b]=true;
 }
 for(int i=1;i<=n;i++)if(visited1[i]==false){src=i;break;}
 pf("%d\n",n-1);
graph();

return 0;
}
/*
Ref: n-1 edges needed to make a connected tree
https://www.youtube.com/watch?v=dYJcfVCGft8
*/

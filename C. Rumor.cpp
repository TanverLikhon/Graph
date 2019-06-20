/*Never Give up*/
/*
Problem  :https://codeforces.com/problemset/problem/893/C
Verdict     :AC
Time         :108 ms	6100 KB
Memory  :
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
#define sz(a)              a.size()
#define ff first
#define ss second
#define all(a)          a.begin(), a.end()
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
#define en        pf("Entered\n")
#define en1      pf("Entered 2\n")
#define MAX    100006
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
int cost[MAX];
vi edge[MAX];int n,m;
ll sum;
int minn=INT_MAX;
bool visited[MAX];
void dfs(int src)
{
   visited[src]=true;
  minn=min(minn,cost[src]);
  for(int i=0;i<sz(edge[src]);i++)
  {
    if(!visited[edge[src][i]])
       dfs(edge[src][i]);
  }

}

int main()
{
sff(n,m);
for(int i=1;i<=n;i++)sf(cost[i]);
while(m--)
{
  int x,y;
  sff(x,y);
  edge[x].pb(y);
  edge[y].pb(x);

}
for(int i=1;i<=n;i++)
  if(!visited[i])dfs(i),sum+=minn,minn=INT_MAX;

pf("%lld\n",sum);

return 0;
}
/*
Ref:
*/

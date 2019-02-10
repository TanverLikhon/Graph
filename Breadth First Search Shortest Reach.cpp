/*Never Give up*/
//https://www.hackerrank.com/challenges/bfsshortreach/problem
#include<bits/stdc++.h>
using namespace std;
#define sf(a)          scanf("%d",&a)
#define sff(a,b)         scanf("%d%d",&a,&b)
#define sfff(a,b,c)         scanf("%d%d%d",&a,&b,&c)
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define v           vector
#define l            list
#define pi          pair
#define mp         map
#define nl         printf("\n")
#define en        pf("Entered\n")
//accepted :)
int n;
v<int>adj[1001];
bool flag=false;
void bfs(int src)
{
int    dis[n+1];
    bool visited[n+1];
    for(int i=0; i<=n; i++)
    {
        visited[i]=false;
        dis[i]=-1;
    }
    visited[src]=true;
        dis[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int x=q.front();

        q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            int tmp=adj[x][i];

            if(visited[tmp]==false)
            {
                visited[tmp]=true;
                dis[tmp]=dis[x]+6;
                q.push(tmp);
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(i!=src)pf("%d ",dis[i]);

    nl;
}
int main()
{
  int t;sf(t);
  while(t--)
  {
      int m;
      sff(n,m);
      while(m--)
      {
          int u,v;
          sff(u,v);
          adj[u].pb(v);
          adj[v].pb(u);
      }
      int src;sf(src);
      bfs(src);
      for(int i=0;i<=n;i++)adj[i].clear();
  }
}

/*Never Give up*/
///http://lightoj.com/volume_showproblem.php?problem=1174
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
//accepted :) 0.001
int n;
int dis[100];
int dis1[100];
v<int>adj[30000];
bool flag=false;
void bfs(int src)
{
    bool visited[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    visited[src]=true;
    if(flag==false)
        dis[src]=0;
    else
        dis1[src]=0;
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
                if(flag==false)
                dis[tmp]=dis[x]+1;
                else
                    dis1[tmp]=dis1[x]+1;
                q.push(tmp);
            }

        }

    }

}
int main()
{
    int t;
    sf(t);
    int ck=1;
    while(t--)
    {
        int src,dest,x,xy;
        sff(n,x);

        while(x--)
        {
            int u,v;
            sff(u,v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        sff(src,dest);
        bfs(src);
        flag=true;
        bfs(dest);
        xy=0;
        for(int i=0; i<n; i++)
        {
            if(dis[i]+dis1[i]>xy)
                xy=dis[i]+dis1[i];
            //cout<<dis[i]<<"  "<<dis1[i]<<endl;
        }
        pf("Case %d: %d\n",ck,xy);
        ck++;
        for(int i=0; i<n; i++)
        {
            adj[i].clear();
      dis[i]=0;
          dis1[i]=0;
        }
        flag=false;
    }
    return 0;
}

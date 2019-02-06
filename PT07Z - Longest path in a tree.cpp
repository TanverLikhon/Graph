//https://www.spoj.com/problems/PT07Z/
/*Never Give up*/
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
//accepted 0.00 sec:)
int n,mx;
v<int>adj[10002];
int bfs(int src)
{
    bool visited[n];
   mx=0;
    int node;
    int dis[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
        dis[i]=0;
    }
    visited[src]=true;
    dis[src]=0;
    queue<int>q;
    q.push(src);
while(!q.empty())
{
    int x=q.front();

    q.pop();
    for(int i=0;i<adj[x].size();i++)
    {
        int tmp=adj[x][i];

        if(visited[tmp]==false)
        {
            visited[tmp]=true;
            dis[tmp]=dis[x]+1;
            if(dis[tmp]>mx)
            {
                mx=dis[tmp];
                node=tmp;
            }
            q.push(tmp);
        }

    }

}

    return node;
}
int main()
{

        sf(n);//en;
        int x=n;
        x--;
        while(x--)
        {
            int u,v;
            sff(u,v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

int xy=bfs(bfs(1));
pf("%d\n",mx);
        for(int i=0; i<n; i++)
            adj[i].clear();
    return 0;
}

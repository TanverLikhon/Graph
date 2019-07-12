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
#define MAX 3000
v<int>edge[MAX];
mp<pi<int,int>,int>weight;
mp<pi<int,int>,bool>kk;
int N,M;
struct cell
{
    int xx,dist;
};
bool operator <  (cell a,cell b)
{
    return b.dist<a.dist;
}
void weightedbfs(int src)
{
    cell zz;
    zz= {src,0};
    priority_queue<cell>q;
    ll dis[N+1];
    for(int i=1; i<=N; i++)
        dis[i]=1e18;
    dis[src]=0;
    q.push(zz);
    while(!q.empty())
    {
        int x=q.top().xx;
        q.pop();
        for(int i=0; i<edge[x].size(); i++)
        {
            int m=edge[x][i];
            int w=weight[ {x,m}];
            if(dis[m]>dis[x]+w)
            {
                dis[m]=dis[x]+w;
                q.push({m,dis[m]});
            }
        }
    }
    for(int i=1; i<=N; i++)
    {
        if(i==src)
            continue;
        else  if(dis[i]==1e18)
            pf("-1 ");
        else
            pf("%d ",dis[i]);
    }
}
int main()
{
    int t;
    sf(t);
    while(t--)
    {
        sff(N,M);
        while(M--)
        {
            int x,y,z;
            sfff(x,y,z);
            if(kk[ {x,y}]==false)
                edge[x].pb(y), edge[y].pb(x);
            kk[ {x,y}]=true,kk[ {y,x}]=true;

            if(weight[ {x,y}]>0&&z<weight[ {x,y}])
                weight[ {x,y}]=z,weight[ {y,x}]=z;
            else if(weight[ {x,y}]==0)
                weight[ {x,y}]=z,weight[ {y,x}]=z;

        }
        int src;
        sf(src);
        weightedbfs(src);
        for(int i=1; i<=N; i++)
        {
            edge[i].clear();
        }
        weight.clear();
        kk.clear();
nl;
    }

    return 0;
}

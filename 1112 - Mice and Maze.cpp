/*Never Give up*/
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3553
#include<bits/stdc++.h>
using namespace std;
#define sf          scanf
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define v           vector
#define l            list
#define pi          pair
#define mp         map
#define nl         printf("\n")
#define MAX   101
//accepted 0.000sec :)
int n,a,b,w,m,e,t;
v<int>edge[MAX];
mp<pi<int,int>,int>weight;
int weightedbfs()
{
    int ck=0;
    int dis[n+1];
    for(int i=1; i<=n; i++)
        dis[i]=INT_MAX;
    dis[e]=0;
    queue<int>q;
    q.push(e);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<edge[x].size(); i++)
        {
            w=weight[ {x,edge[x][i]}];
            if(dis[edge[x][i]]>w+dis[x])
            {
                dis[edge[x][i]]=w+dis[x];
                q.push(edge[x][i]);
            }

        }

    }
    for(int i=1; i<=n; i++)
        if(dis[i]<=t)
            ck++;
    return ck;
}
int main()
{
    int T;
    sf("%d",&T);
    while(T--)
    {
        sf("%d%d%d%d",&n,&e,&t,&m);
        while(m--)
        {
            sf("%d%d%d",&a,&b,&w);
            edge[b].pb(a);

         //   edge[a].pb(b);
            weight[ {b,a}]=w;
        }
        pf("%d\n",weightedbfs());
        weight.clear();
        for(int i=1; i<=n; i++)
            edge[i].clear();
            if(T>0)nl;
    }


    return 0;
}

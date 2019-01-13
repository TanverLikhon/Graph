/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927&fbclid=IwAR1LmPJBCLT96pcrTjuirg_7_wuzJEF_2cwIGx_R5QCP7h826ZY-jXTltjI*/
#include<bits/stdc++.h>
using namespace std;
#define sf          scanf
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define v           vector
#define l            list
#define p          pair
#define m         map
#define nl         printf("\n")
#define MAX  20000
int n,M,s,t,x,y,z,w;
v<int>edge[MAX];
m<p<int,int>,int>weight;
///accepted 0.576sec:)
int weightedbfs(int src,int dest)
{
queue<int>q;
    int dis[n];
    for(int i=0;i<n;i++)
        dis[i]=INT_MAX;
    dis[src]=0;
    q.push(src);
    while(!q.empty())
    {
       x=q.front();
       q.pop();
       for(int i=0;i<edge[x].size();i++)
       {
           w=weight[{x,edge[x][i]}];
           if(dis[edge[x][i]]>dis[x]+w)
           {
               dis[edge[x][i]]=dis[x]+w;
               q.push(edge[x][i]);
           }
       }
    }

    if(dis[dest]!=INT_MAX)return dis[dest];
    else return -1;
}
int main()
{
int T,ck=1;;
sf("%d",&T);
while(T--)
{
    sf("%d%d%d%d",&n,&M,&s,&t);
    while(M--)
    {
        sf("%d%d%d",&x,&y,&w);
        edge[x].pb(y);
        edge[y].pb(x);
        weight[{x,y}]=w;
        weight[{y,x}]=w;
    }
    int W=weightedbfs(s,t);
    if(W==-1)pf("Case #%d: unreachable\n",ck);
    else pf("Case #%d: %d\n",ck,W);
    ck++;
    weight.clear();
    for(int i=0;i<n;i++)edge[i].clear();
}

return 0;
}

///https://codeforces.com/contest/20/problem/C
#include<bits/stdc++.h>
using namespace std;
#define sf          scanf
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define v          vector
#define l            list
#define p          pair
#define m         map
#define nl         printf("\n")
#define mpp    make_pair
#define MAX   100005
///accepted 115ms 15100kB
v<int>edge[MAX];
m<p<int,int>,int>weight;
int N,M;
int parent[MAX];
void print(int i)
{
    if(i!=1)
        print(parent[i]);
    pf("%d ",i);

}
void weightedbfs()
{
    priority_queue<int>q;
    ll dis[N+1];
    for(int i=2; i<=N; i++)
        dis[i]=1e18;
    dis[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int x=q.top();
        q.pop();
        for(int i=0; i<edge[x].size(); i++)
        {
            int m=edge[x][i];
            int w=weight[ {x,m}];
            if(dis[m]>dis[x]+w)
            {
                dis[m]=dis[x]+w;
                q.push(m);
                parent[m]=x;
            }
        }
    }
    if(dis[N]==1e18)
        pf("-1\n");
    else
        print(N);
}
int main()
{
    sf("%d%d",&N,&M);
    while(M--)
    {
        int x,y,z;
        sf("%d%d%d",&x,&y,&z);
        edge[x].pb(y);
        edge[y].pb(x);
        weight[ {x,y}]=z;
        weight[ {y,x}]=z;

    }
    weightedbfs();
    return 0;
}
///C.Duhjkstra?
/*Tanver Ahmed Likhon*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
///300+ms but 9944 kB
vector<pair<ll,int> >adj[100009];
ll dis[100009];
int par[100008];
bool vis[100009];
void dijakstra(int u,int v)
{
    for(int i=1; i<=v; i++)
        dis[i]=inf;

    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int>> >pq;
    pq.push({0ll,u});
    dis[u]=0ll;
    while(!pq.empty())
    {
        u=pq.top().second;

        pq.pop();
        vis[u]=true;

        for(auto x :adj[u])
        {
            int v=x.second;
            ll w=(ll)x.first;

            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                par[v]=u;
                if(!vis[v])
                {
                    pq.push({dis[v],v});
                }
            }
        }
    }

}

void path(int u,int v)
{
    if(par[v])
    {
        path(u,par[v]);
    }
    u!=v?printf(" %d",v):printf("%d",v);
}
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    dijakstra(1,n);
    if(vis[n])
        path(1,n);
    else
        cout<<"-1"<<endl;
    return 0;
}

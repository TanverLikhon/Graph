#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101],cost[101];
int dist[101],par[101];

bool Bellman_Ford(int src, int n, int e)
{
    int i,j,x,k,u,v;
    memset(dist,INT_MAX,sizeof(dist));
    dist[x]=0;
    par[x]=0;
    for(i=1; i<n; i++)
    {
        for(k=1; k<=n; k++)
        {
            for(j=0; j<adj[k].size(); j++)
            {
                u=adj[k][j];
                if(dist[k]+cost[k][j]<dist[u])
                {
                    dist[u]=dist[k]+cost[k][j];
                    par[u]=k;
                }
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=0; j<adj[i].size(); j++)
        {
            u=adj[i][j];
            if(dist[i]+cost[i][j]<dist[u])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int i,j,edge,node,u,v,w;
    while(cin>>node>>edge)
    {
        if(!node && !edge)
            break;
        for(i=1; i<=edge; i++)
        {
            cin>>u>>v>>w;
            adj[u].push_back(v);
            cost[u].push_back(w);
        }
        if(Bellman_Ford(1,node,edge))
            printf("No Negative Weight Cycle");
        else
            printf("Negative Weight Cycle");
    }
    return 0;
}

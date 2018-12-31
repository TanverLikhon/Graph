/*tanverlikhon@gmail.com*/
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
#define white 1
#define gray   2
#define black 3
int adj[100][100];
int node,edge;
int color[100];
int parent[100];
int dis[100];
void bfs(int startingNode)
{
    for(int i=0; i<node; i++)
    {
        color[i]=white;
        dis[i]=INT_MIN;
        parent[i]=-1;
    }
    dis[startingNode]=0;
    parent[startingNode]=-1;
    queue<int >q;
    q.push(startingNode);
    while(!q.empty())
    {
        int x;
        x=q.front();
        q.pop();
        color[x]=gray;
        pf("%d ",x);
        ///some work
        for(int i=0; i<node; i++)
        {
            if(adj[x][i]==1)
            {
                if(color[i]==white)
                {
                    //i is the neighbour of x
                    //x is the parent of i
                    dis[i]=dis[x]+1;
                    parent[i]=x;
                    q.push(i);
                }
            }
        }
        color[x]=black;
    }
}
int main()
{
    sf("%d%d",&node,&edge);
    int n1,n2;
    for(int i=0; i<edge; i++)
    {
        sf("%d%d",&n1,&n2);
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }
    bfs(0);

    return 0;
}


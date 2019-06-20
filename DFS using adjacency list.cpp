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
#define MAX   100001
using namespace std;
vector <int> adj[MAX];
bool visited[MAX];
int nodes, edges, x, y, ck = 0;
void dfs(int s)
{
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
            ck++;
        }
    }
}

void initialize()
{
for(int i=1;i<=nodes;i++)visited[i]=false;
}

int main()
{
    int t;
    sf(t);
    while(t--)
    {
           sf(nodes);
   edges=nodes-1;
    for(int i = 0; i < edges; ++i)
    {
      sff(x,y);
        adj[x].push_back(y);
    }

    initialize();

    for(int i = 1; i <= nodes; ++i)
    {
        if(visited[i] == false)
        {
            dfs(i);

        }
    }
    cout<<ck<<endl;
    for(int i=1;i<=nodes;i++)adj[i].clear();
    ck=0;
    }

    return 0;
}

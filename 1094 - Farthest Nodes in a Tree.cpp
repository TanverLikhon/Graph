//http://lightoj.com/volume_showproblem.php?problem=1094
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
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//accepted 0.586 sec
int n,mx;
v<int>adj[30000];
mp<pi<int,int>,int>weight;
int bfs(int src)
{
//cout<<n<<endl;
//cout<<"S "<<src<<"  "<<mx<<endl;
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
                  //  cout<<"Dis  "<<tmp<<"   "<<dis[tmp]<<endl;
            dis[tmp]=dis[x]+weight[{x,tmp}];
       //    cout<<"Dis "<<tmp<<"   "<<dis[tmp]<<endl;
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
    int t;
    sf(t);
int ck=1;
    while(t--)
    {
        sf(n);//en;
        int x=n;
        x--;
        while(x--)
        {
            int u,v,w;
            sfff(u,v,w);
            adj[u].pb(v);
            adj[v].pb(u);
            weight[ {u,v}]=w;
            weight[ {v,u}]=w;
        }

int xy=bfs(bfs(0));
pf("Case %d: %d\n",ck,mx);ck++;
        for(int i=0; i<n; i++)
            adj[i].clear();
            weight.clear();
    }
    return 0;
}

/*Never Give up*/
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1900
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
//accepted 0.00 second rank644
int p,n;
v<int>edge[1001];
int dis[1001];
void bfs()
{

    bool visited[p];
    for(int i=0; i<p; i++)
    {
        visited[i]=false,dis[p]=0;
    }
    dis[0]=0,visited[0]=true;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<edge[x].size(); i++)
        {
            int u=edge[x][i];
            if(visited[u]==false)
            {
                visited[u]=true;
                dis[u]=dis[x]+1;
                q.push(u);
            }
        }
    }
}
int main()
{
    int t;
    sf(t);
    while(t--)
    {
        sff(p,n);
        while(n--)
        {
            int x,y;
            sff(x,y);
            edge[x].pb(y);
            edge[y].pb(x);
        }
        bfs();
        for(int i=1; i<p; i++)
            pf("%d\n",dis[i]);
            for(int i=0;i<p;i++)
                edge[i].clear();
            if(t)nl;
    }


    return 0;

}

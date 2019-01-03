/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=508*/
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
///accepted 0.080 sec :)
v<int>edge[21];
int bfs(int startingNode,int endingNode)
{
    queue<int >q;
    int visit[21]= {0},dis[21];
    visit[startingNode]=1;
    dis[startingNode]=0;
    q.push(startingNode);
    while(!q.empty())
    {
        int x= q.front();
        q.pop();
        for(int i=0; i<edge[x].size(); i++)
        {
            if(visit[edge[x][i]]==0)
            {
                visit[edge[x][i]]=1;
                dis[edge[x][i]]=dis[x]+1;
                q.push(edge[x][i]);
            }
        }
    }
 /*for(int i=1;i<21;i++)
    cout<<i<<"->"<<dis[i]<<endl;*/

    return dis[endingNode];
}
int main()
{
    int x,y;
    int k=1;

    while(sf("%d",&x)!=EOF)
    {
        while(x--)
        {
            sf("%d",&y);
            edge[1].pb(y);
            edge[y].pb(1);
        }

        for(int i=2; i<20; i++)
        {
            sf("%d",&x);
            while(x--)
            {
                sf("%d",&y);
                edge[i].pb(y);
                edge[y].pb(i);
            }
        }
        int t;
 pf("Test Set #%d\n",k);
        sf("%d",&t);
        while(t--)
        {
            int n1,n2;
            sf("%d%d",&n1,&n2);
            int z=bfs(n1,n2);
   pf("%2d to %2d: %d\n",n1,n2,bfs(n1,n2));
        }
        nl;
        k++;
        for(int i=0;i<21;i++)edge[i].clear();
    }


    return 0;
}



/*Never Give up*/
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
#define mp         map
#define nl         printf("\n")
#define MAX   1001
int n,q,m,n1,n2;
v<int>edge[MAX];
int bfs(int start)
{
    //cout<<"Entered "<<endl;
    int max=0;
    int dis[n]= {0};
    dis[start]=0;
    bool visited[n]= {false};
//cout<<"dis"<<visited[3]<<endl;
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<edge[x].size(); i++)
        {
            int to=edge[x][i];
            if(visited[to]==false)
            {
                visited[to]=true;
                dis[to]=dis[x]+1;
                if(dis[to]>max)
                    max=dis[to];
                    //cout<<x<<"->"<<to<<"   ";
                 //   cout<<dis[to]<<endl;
                q.push(to);
            }

        }
    }
   // cout<<max<<endl;
    return max;

}
int main()
{
    int s,d;
    int ck=1;
    sf("%d",&q);
    while(q--)
    {
        int result;
        sf("%d%d",&n,&m);
        while(m--)
        {
            sf("%d%d",&n1,&n2);
            edge[n1].pb(n2);
            edge[n2].pb(n1);
        }
        sf("%d%d",&s,&d);
        cout<<bfs(s)<<"   "<<bfs(d)<<endl;
        result=bfs(s)+bfs(d);
        pf("Case %d: %d\n",ck,result);
       for(int i=0;i<n;i++)edge[i].clear();
       ck++;
    }

    // cout<<"e  "<<endl;


    return 0;
}

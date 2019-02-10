/*Never Give up*/
//http://lightoj.com/volume_showproblem.php?problem=1257
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
//accepted 0.687 sec:(
int n,mx;
v<int>adj[30000];
mp<pi<int,int>,int>weight;
int dis[30000];
int dis1[30000];
bool flag=false;
int bfs(int src)
{
  //  cout<<"F  "<<flag<<endl;
    bool visited[n];
    mx=0;
    int node;
    //if(flag==false)
        for(int i=0; i<n; i++)
        {
            visited[i]=false;
           if(flag==false)dis[i]=0;
        }

    visited[src]=true;
    if(flag==false)
        dis[src]=0;
        else dis1[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int x=q.front();

        q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            int tmp=adj[x][i];

            if(visited[tmp]==false)
            {
                visited[tmp]=true;
                if(flag==false)
                {
                    dis[tmp]=dis[x]+weight[ {x,tmp}];
                    if(dis[tmp]>mx)
                    {
                        mx=dis[tmp];
                        node=tmp;
                    }
                }
                else
                {
                    dis1[tmp]=dis1[x]+weight[ {x,tmp}];
                    if(dis1[tmp]>mx)
                    {  // en;
                        mx=dis1[tmp];
                        node=tmp;
                    }
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
        int y=bfs(0);

        int xy=bfs(y);
                flag=true;
                xy=bfs(xy);
                flag=false;
        //dis[y]=dis[xy]=mx;
        // cout<<y<<"    "<<xy<<endl;
        pf("Case %d:\n",ck);
        ck++;
   //     cout<<mx<<endl;
        for(int i=0; i<n; i++)
        {
         //  cout<<dis[i]<<"   "<<dis1[i]<<endl;
            pf("%d\n",max(dis[i],dis1[i]));
            adj[i].clear();
            dis[i]=dis1[i]=0;
        }
        weight.clear();
    }
    return 0;
}

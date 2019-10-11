/*Never Give up*/
/*
Problem  :https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1390
Verdict     :AC
Time         :
Memory  :
*/
#include<bits/stdc++.h>
using namespace std;
#define sf(a)          scanf("%d",&a)
#define sff(a,b)         scanf("%d%d",&a,&b)
#define sfff(a,b,c)         scanf("%d%d%d",&a,&b,&c)
#define sffff(a,b,c,d)         scanf("%d%d%d%d",&a,&b,&c,&d)
#define sl(a)          scanf("%lld",&a)
#define sll(a,b)         scanf("%lld%lld",&a,&b)
#define slll(a,b,c)         scanf("%lld%lld%lld",&a,&b,&c)
#define sllll(a,b,c,d)         scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define sc(a) scanf("%c",&a)
#define sz(a)              a.size()
#define ff first
#define ss second
#define all(a)          a.begin(), a.end()
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pf         printf
#define pf1(a)        pf("%d\n",a);
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define vi           vector<int>
#define vl           vector<ll>
#define li            list<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define mp         map
#define nl         printf("\n")
#define en        pf("Entered\n")
#define en1      pf("Entered 2\n")
#define gcd(a,b) __gcd(a,b)

// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    1000

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
//vi adj[MAX];
int node,edge;
ll dis[MAX];


void BellmanFord(int graph[][3],int src)
{

    for (int i = 1; i <= node; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;
    for (int i = 1; i <= node - 1; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            if (dis[graph[j][0]]!=INT_MAX&&dis[graph[j][0]] + graph[j][2] <dis[graph[j][1]])
                dis[graph[j][1]] =dis[graph[j][0]] + graph[j][2];
        }
    }

    for (int i = 0; i < edge; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x]!=INT_MAX&&dis[x] + weight < dis[y])
           dis[y]=INT_MIN;
    }

}
int main()
{
    int kk=1;
    int n,e;
    while(sf(n)==1)
    {
        node=n;
        int dist[n+1];
        for(int i=1; i<=n; i++)
            sf(dist[i]);

        sf(e);
        edge=e;
        int graph[e][3];
        for(int i=0; i<e; i++)
        {

            int u,v;
            sff(u,v);
            graph[i][0]=u;
            graph[i][1]=v;
            graph[i][2]=(dist[v]-dist[u])*(dist[v]-dist[u])*(dist[v]-dist[u]);

        }
        BellmanFord(graph,1);

     //   for(int i=1;i<=n;i++)
     //  cout<<i<<" --  "<<dis[i]<<endl;

        pf("Set #%d\n",kk++);
        int q;
        sf(q);
        while(q--)
        {
            int x;
            sf(x);
          if(dis[x]<3||dis[x]==INT_MAX)pf("?\n");

           else pf("%lld\n",dis[x]);
        }

    }


    return 0;
}
/*
Ref:
*/


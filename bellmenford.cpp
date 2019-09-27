/*Never Give up*/
/*
Problem  :
Verdict     :
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
#define pf1        pf("%d\n");
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
vi adj[MAX];
map<pi,int>weight;
int node,edge;
void BellmanFord(int graph[][3],int src)
{
    int dis[node];
    for (int i = 0; i < node; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;
    for (int i = 0; i < node - 1; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            if (dis[graph[j][0]] + graph[j][2] <
                    dis[graph[j][1]])
                dis[graph[j][1]] =
                    dis[graph[j][0]] + graph[j][2];
        }
    }
    for (int i = 0; i < E; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX &&
                dis[x] + weight < dis[y])
            cout << "Graph contains negative"
                 " weight cycle"
                 << endl;
    }
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dis[i] << endl;
}
int main()
{

    int n,e;
    sff(n,e);
    node=n,edge=e;
    int graph[e][3];
    for(int i=0; i<e; i++)
    {

        int u,v,w;
        sfff(u,v,w);
        graph[i][0]=u;
        graph[i][1]=v;
        graph[i][2]=w;

    }
    int src;
    sf(src);
    BellmanFord(graph,src);

    return 0;
}
/*
Ref:
*/


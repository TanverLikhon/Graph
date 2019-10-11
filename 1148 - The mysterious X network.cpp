/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3589
Verdict     :AC
Time         :0.150
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
#define PI            acos(-1.0)

// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    100001

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
int node,edge,src,dest;
vi adj[MAX];
int bfs()
{
    bool visited[node];
    int dist[node];
    for(int i=0; i<node; i++)
        visited[i]=false,dist[i]=INT_MAX;
    visited[src]=true;
    dist[src]=0;

    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
   if(u==dest)return dist[dest]-1;
        for(int i=0; i<sz(adj[u]); i++)
        {
            int x=adj[u][i];
            if(!visited[x])
            {
                visited[x]=true;
                dist[x]=dist[u]+1;
                q.push(x);
            }
        }
    }
   //for(int i=0;i<node;i++)
      //  cout<<i<<"----"<<dist[i]<<endl;
    return dist[dest]-1;
}
int main()
{
    int t;
    sf(t);
    while(t--)
    {
        sf(node);
        for(int i=0; i<node; i++)
        {
            int x,y,z;
            sff(x,y);
            while(y--)
            {
                sf(z);
                adj[x].pb(z);
                adj[z].pb(x);
            }
        }
        sff(src,dest);

pf("%d %d %d\n",src,dest,bfs());
for(int i=0;i<node;i++)adj[i].clear();
if(t)nl;
    }
    return 0;
}
/*
Ref:
*/


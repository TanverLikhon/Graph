/*Never Give up*/
/*
Problem  :https://www.hackerrank.com/challenges/jack-goes-to-rapture/problem
Verdict     :AC
Time         :1497ms
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

#define MAX    500006

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
vector<pi> adj[MAX];

map<pi,int>weight;
int node,edge;

struct cell
{
    int xx,dist;
};
bool operator <  (cell a,cell b)
{
    return b.dist<a.dist;
}

ll bfs()
{
    ll dist[node+1];
    for(int i=1; i<=node; i++)
    {
        dist[i]=INT_MAX;
    }
    cell zz;
    zz= {1,0};
    dist[1]=0;
    priority_queue<cell>q;
    q.push(zz);
    while(!q.empty())
    {
        int u=q.top().xx;
        q.pop();
        for(int i=0; i<sz(adj[u]); i++)
        {
            int x=adj[u][i].first;
            ll w=adj[u][i].second;
            //ll w=weight[ {u,x}];

            int tmp=max(dist[u],w);
            if(tmp<dist[x])
            dist[x]=tmp,q.push({x,dist[x]});


           /* if(dist[u]>w&&dist[x]>dist[u]&&x!=u)
            {
                dist[x]=dist[u];
                q.push({x,dist[x]});
            }
            else if(dist[u]<=w&&dist[x]>w&&x!=u)
            {
                dist[x]=w;
                q.push({x,dist[x]});
            }*/
        }

    }



    return dist[node];
}
int main()
{
    sff(node,edge);
    int x,y,z;
    for(int i=0; i<edge; i++)
    {
        sfff(x,y,z);
        adj[x].pb({y,z});
        adj[y].pb({x,z});
        // weight[ {min(x,y),max(x,y)}]=z;
        //adj[min(x,y)].pb(max(x,y));
      //  weight[ {x,y}]=z;
      //  weight[ {y,x}]=z;
      //  adj[x].pb(y);
      //  adj[y].pb(x);

    }
    if(bfs()==INT_MAX)pf("NO PATH EXISTS\n");
    else pf("%lld\n",bfs());

    return 0;
}
/*
Ref:
*/

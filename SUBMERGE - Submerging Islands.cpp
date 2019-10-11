/*Never Give up*/
/*
Problem  :https://www.spoj.com/problems/SUBMERGE/
Verdict     :AC
Time         :0.02sec
Memory  :5.6M
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


//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
//MAXN = maximum points in the graph
#define MAXX 10005
vi adj[MAXX];
bool vis[MAXX],AP[MAXX];
int parent[MAXX],low[MAXX],disc[MAXX];
int tim;
int nodes,edges;
void initilize(int n)
{
    int i;
    for(i =1; i<=n; i++)
    {
        vis[i]=AP[i]=false;
        parent[i]=-1;
        adj[i].clear();
        low[i]=0;

    }
    tim=0;
}

void dfs(int u)
{
    vis[u]=true;
    int  i;
    low[u]=disc[u]=(++tim);
    int child=0;
    for(i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(vis[v]==false)
        {
            child++;
            parent[v]=u;
            dfs(v);

            low[u]=min(low[u],low[v]);
            if( (parent[u]!=-1) and ( low[v]>=disc[u] ) )
                AP[u]=true;
            if( (parent[u]==-1) and (child>1))
                AP[u]=true;
        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],disc[v]);
        }
    }
}
int main()
{
    int n,e;
    while(  sff(n,e)&&n&&e)
    {
        initilize(n);
        for(int i=0; i<e; i++)
        {
            int x,y;
            sff(x,y);
            adj[x].pb(y);
            adj[y].pb(x);

        }
        dfs(1);
        int res=0;
        for(int i=1;i<=n;i++)
        if(AP[i])res++;
        pf1(res);
    }

    return 0;
}


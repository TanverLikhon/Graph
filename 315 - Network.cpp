/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=251
Verdict     :AC
Time         :0.00
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

#define MAX    105

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
vi adj[MAX];
//vi adj[MAX];
bool vis[MAX],AP[MAX];
int parent[MAX],low[MAX],disc[MAX];
int tim;
int nodes,edges;
void initilize(int n)
{
    int i;
    for(i =1; i<=n; i++)
    {
        vis[i]=AP[i]=false;
        parent[i]=-1;
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
    int n;
    while(sf(n)&&n)
    {
        cin.ignore();
        string str;
        int mx=-1;
        while(getline(cin,str)&&str!="0")
        {
            stringstream ss(str);
            int u,v;
            ss>>u;
            mx=max(mx,u);
          //  cout<<u<<" ";
            while(ss>>v)
            {
                mx=max(mx,v);
             //   cout<<v<<" ";
                adj[u].pb(v);
                adj[v].pb(u);
            }

        }
        initilize(mx);
        dfs(1);
        int ck=0;
        for(int i=1; i<=mx; i++)
            if(AP[i])
                ck++;
        pf1(ck);

        for(int i=1; i<=mx; i++)
            adj[i].clear();
    }
    return 0;
}
/*
Ref:
*/


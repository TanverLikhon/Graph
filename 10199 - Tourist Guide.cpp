/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1140
Verdict     :AC
Time         :0.010s 858th
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

#define MAX    100000

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
mp<string,int>idx;
mp<int,string>id;
vi adj[MAX];
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
        adj[i].clear();
    }
    tim=0;
    idx.clear(),id.clear();
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
   int n;int k=1;
   while(sf(n))
   {
     if(n==0)return 0;
       if(k!=1)nl;

        initilize(n);
       for(int i=1;i<=n;i++)
       {
                string str; cin>>str;
                idx[str]=i;
                id[i]=str;
       }
       sf(edges);
       for(int i=0;i<edges;i++)
       {
           string str,str1;
           cin>>str>>str1;
           adj[idx[str]].pb(idx[str1]);
           adj[idx[str1]].pb(idx[str]);
       }
       for(int i=1;i<=n;i++)
        if(vis[i]==false)
       dfs(i);
       vector<string>arr;
       for(int i=1;i<=n;i++)
        if(AP[i])arr.pb(id[i]);
     sort(arr.begin(),arr.end());
       pf("City map #%d: %d camera(s) found\n",k++,sz(arr));
       for(int i=0;i<sz(arr);i++)
       cout<<arr[i]<<endl;

   }



return 0;
}
/*
Ref:
6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
7
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado
5
guanabarabay
downtown
botanicgarden
colombo
sambodromo
4
guanabarabay sambodromo
downtown sambodromo
sambodromo botanicgarden
colombo sambodromo
0
*/


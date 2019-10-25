/*Never Give up*/
/*
Problem  :https://codeforces.com/contest/277/problem/A
Verdict     :AC
Time         :62 ms	400 KB
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
#define PI  acos(-1)
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
#define sp  ' '
// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    105

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
vi adj[MAX];;
vi lang[MAX];
bool visited[MAX];
int p[MAX];
int n,m;
int root(int x)
{
    while(p[x]!=x)
    {
        p[x]=p[p[x]];
        x=p[x];
    }
    return x;
}
void dfs(int src)
{
    visited[src]=true;
    for(int i=0; i<sz(adj[src]); i++)
    {
        if(visited[adj[src][i]]==false)
        {

            p[adj[src][i]]=root(src);
            dfs(adj[src][i]);
        }

    }
}
int main()
{
    faster
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        p[i]=i;
   int ck=0;
    int mn=INT_MAX,mx=INT_MIN;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if(x==0)ck++;
        for(int k=0; k<x; k++)
        {
            int y;
            cin>>y;
            mn=min(mn,y),mx=max(mx,y);
            lang[y].pb(i);

        }
    }

    for(int i=mn; i<=mx; i++)
    {
        int tt;
        if(sz(lang[i]))
            tt=lang[i][0];
        for(int k=1; k<sz(lang[i]); k++)
        {
            adj[tt].pb(lang[i][k]);
            adj[lang[i][k]].pb(tt);
            tt=lang[i][k];
        }

    }
set<int>st;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
            dfs(i);

    }

    for(int i=1; i<=n; i++)st.insert(p[i]);
       // cout<<"node "<<i<<" parent "<<p[i]<<endl;
       if(ck==n)cout<<n<<endl;
       else
cout<<sz(st)-1<<endl;

    return 0;
}
/*
Ref:
*/

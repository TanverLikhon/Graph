/*Never Give up*/
/*
Problem  :https://codeforces.com/problemset/problem/1249/B2
Verdict     :AC
Time         :108 ms	12900 KB
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

#define MAX    200005

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
int dist[MAX];
bool visited[MAX];
vi adj[MAX];
int ck;
void dfs(int src)
{
    visited[src]=true;
    ck++;
    for(int i=0; i<sz(adj[src]); i++)
    {
        if(!visited[adj[src][i]])
            dfs(adj[src][i]);
    }
    dist[src]=ck;
}
int main()
{
    faster
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            visited[i]=false,dist[i]=0;
            int x;
            cin>>x;
            if(i==x)
                visited[i]=true,dist[i]=1;
            else
                adj[i].pb(x);
        }
      //  cout<<"res "<<endl;
        for(int i=1; i<=n; i++)
        {
            ck=0;
            if(!visited[i])
                dfs(i);

            cout<<dist[i]<<" ",adj[i].clear();

        }
        cout<<endl;
//for(int i=1;i<=n;i++)adj[i].clear();

    }




    return 0;
}
/*
Ref:
*/

/*Never Give up*/
/*
Problem  :https://codeforces.com/contest/580/problem/C
Verdict     :AC
Time         :124 ms	6200 KB
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
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pf         printf
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
#define MAX 100002
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
vector <int> adj[MAX];
int n,m;
bool arr[MAX];
bool visited[MAX];
int cats[MAX];
int nodes, edges,ck = 0;
void dfs(int x,int p)
{
    visited[x]= true;
    if(arr[p]==1&&arr[x]==1)
        cats[x]=cats[p]+1;
        else if(arr[x])cats[x]=1;
    if(cats[x]>m)
        return;
    for(int i = 0; i<adj[x].sz; ++i)
    {
        int tmp=adj[x][i];
        if(visited[tmp]== false)
        {
            dfs(tmp,x);
        }
    }
    if(adj[x].sz==1)
        ck++;
}

void initialize()
{
    for(int i=1; i<=nodes; i++)
        visited[i]=false,cats[i]=0;
}
int main()
{
    sff(nodes,m);
    n=nodes;
    edges=n-1;
    for(int i=1; i<=n; i++)
        sf(arr[i]);
    for(int i=0; i<edges; i++)
    {
        int x,y;
        sff(x,y);
        adj[y].pb(x);
        adj[x].pb(y);
    }
    initialize();
    if(arr[1])
        cats[1]=1;
    visited[1]=true;
        for(int i=0; i<adj[1].sz; i++)
        {
            if(visited[adj[1][i]]==false)
                dfs(adj[1][i],1);
        }
    pf("%d\n",ck);
    return 0;
}

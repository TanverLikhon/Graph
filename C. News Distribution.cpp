/*Never Give up*/
/*
Problem  :https://codeforces.com/problemset/problem/1167/C
Verdict     :AC
Time         :686 ms	45700 KB
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

#define MAX    500002

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
int node,edge;
vi adj[MAX];
bool visited[MAX];
//int dist[MAX];
int ck;
int track;
mp<int,int>idx;
mp<int,int>dist;
void dfs(int src)
{

    ck++;
    visited[src]=true;
    for(int i=0; i<sz(adj[src]); i++)
    {
        int x= adj[src][i];
        if(!visited[x])
            dfs(x);
    }
    idx[src]=track;
    dist[track]=ck;
}
int main()
{
    sff(node,edge);
    for(int k=0; k<edge; k++)
    {
        int t,tmp;
        sf(t);
        if(t)
            sf(tmp);
        for(int i=1; i<t; i++)
        {
            int x;
            sf(x);
            adj[x].pb(tmp);
            adj[tmp].pb(x);
            tmp=x;
        }
    }
    for(int i=1; i<=node; i++)
    {
        ck=0;
        if(!visited[i])
        {
            track=i;
            dfs(i);
        }
    }
    for(int i=1;i<=node;i++)
    {
     int tmp1= idx[i];
     pf("%d ",dist[tmp1]);
    }

    return 0;
}
/*
Ref:
*/




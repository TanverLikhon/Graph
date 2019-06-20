/*Never Give up*/
/*
Problem  :http://lightoj.com/volume_showproblem.php?problem=1111
Verdict     :Accepted
Time         :0.013
Memory  :2248
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
#define MAX 1001
vector <int> adj[MAX];
bool visited[MAX];
int dis[MAX];
int nodes, edges, x, y;
void dfs(int s)
{
    visited[s] = true;
    dis[s]++;
    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
        }
    }
  //  en;
}

void initialize()
{
    for(int i=1; i<=nodes; i++)
        visited[i]=false;
}

int main()
{
    int t;
    sf(t);int c=1;
    while(t--)
    {
        int k,n;
        sfff(k,nodes,edges);
         int arr[k];
         for(int i=0;i<k;i++)sf(arr[i]);
         for(int i=1;i<=nodes;i++)dis[i]=0;
        for(int i = 0; i < edges; i++)
        {
            sff(x,y);
            adj[x].push_back(y);
        }
        for(int i = 0; i <k; ++i)
        {
            if(visited[arr[i]] == false)
            {
                dfs(arr[i]);
            }        initialize();
        }
         int  ck=0;
        for(int i=1; i<=nodes; i++)
        {
            if(dis[i]==k)ck++;
            adj[i].clear();
        }
    pf("Case %d: %d\n",c++,ck);
    }

    return 0;
}

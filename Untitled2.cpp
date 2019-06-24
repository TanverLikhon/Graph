/*Never Give up*/
/*
Problem  :
Verdict     :
Time         :
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
bool visited[MAX];
//priority_queue<int>q;
map<int,bool>m;
int nodes, edges, x, y, ck = 0;
void dfs(int s)
{
pf("%d ",s);
    visited[s] = true;
    int x=adj[s].sz;
    for(int i = 0; i < x; ++i)
    {
        if(visited[adj[s][i]] == false)
        {
            if(x>=3)if(adj[s][1]>adj[s][2])swap(adj[s][1],adj[s][2]);
            dfs(adj[s][i]);
        }
    }
}
void initialize()
{
    for(int i=1; i<=nodes; i++)
       {
           visited[i]=false;
         //  cout<<i<<"- >";nl;nl;
          // for(int j=0;j<adj[i].size();j++)
          //  cout<<adj[i][j]<<"  ";
       //     nl;
//sort(adj[i].begin(),adj[i].begin()+3);
       }

}
int main()
{
    sff(nodes,edges);

    for(int i = 0; i < edges; ++i)
    {
        sff(x,y);
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    initialize();
    for(int i = 1; i <=nodes; ++i)
    {
        if(visited[i] == false)
        {
            dfs(i);
        }
    }
    return 0;
}

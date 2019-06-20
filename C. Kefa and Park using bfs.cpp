/*Never Give up*/
/*
Problem  :https://codeforces.com/contest/580/problem/C
Verdict     :AC
Time         :93 ms	4500 KB
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
vector<int>adj[MAX];
int n,m;
bool arr[MAX];
bool visited[MAX];
int cats[MAX];
int nodes, edges;
void bfs()
{
    // en;
    int s=1;
    if(arr[1])
        cats[1]=1;
    queue< int >q;
    visited[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        //cout<<u<<"  <-u";
 //       cout<<u<<" "<<cats[u]<<endl;
        for(int l=0; l<adj[u].size(); l++)
        {
            int v = adj[u][l];
            // cout<<visited[v]<<" ";
            if(!visited[v])
            {
                //visited[v]=true;
                if(arr[u]&&arr[v]&&cats[u]+1>m)continue;
                else
                {
                        //cout<<v<<" - "<<cats[v]<<endl;
                    if(arr[u]&&arr[v]&&cats[u]+1<=m)
                        cats[v]=cats[u]+1;
                     else if(arr[v])cats[v]=1;
                    visited[v]=true;               //         cout<<v<<" - "<<cats[v]<<endl;

                    q.push(v);
                }
            }
        }
        q.pop();//en;
    }
    /*  cout<<"printing "<<endl;
      for(int i=1;i<=nodes;i++)
          cout<<i<<"  "<<cats[i]<<" "<<visited[i]<<endl;
          nl,nl;*/
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
    bfs();
    int ck=0;
    for(int i=2; i<=nodes; i++)
    {
        if(adj[i].sz==1)
        {
            //   cout<<i<<"  "<<cats[i]<<endl;
            if(visited[i]&&cats[i]<=m)
                ck++;
        }
    }
pf("%d\n",ck);    return 0;
}


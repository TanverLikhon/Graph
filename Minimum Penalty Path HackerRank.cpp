/*Never Give up*/
/*
Problem  :https://www.hackerrank.com/challenges/beautiful-path/problem
Verdict     :AC
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
#define sz(a)              a.size()
#define ff first
#define ss second
#define all(a)          a.begin(), a.end()
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pf         printf
#define pf1        pf("%d\n");
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define vi           vector<int>
#define vl           vector<ll>
#define li            list<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define vp vector<pi>
#define mp         map
#define nl         printf("\n")
#define en        pf("Entered\n")
#define en1      pf("Entered 2\n")
#define gcd(a,b) __gcd(a,b)

// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    10005

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
vp adj[MAX];
bool visited[MAX][MAX];
int bfs(int src,int dest)
{
    queue<pi>q;
    int mn=1e9;
    q.push({src,0});
    while(!q.empty())
    {
        pi u=q.front();
        q.pop();
        int pn=u.ff,pd=u.ss;
        for(int i=0; i<sz(adj[pn]); i++)
        {
          pi child =adj[pn][i];
          if(!visited[child.ff][u.ss|child.ss])
          {
              visited[child.ff][u.ss|child.ss]=1;
              q.push({child.ff,u.ss|child.ss});
              if(child.ff==dest)mn=min(mn,child.ss|u.ss);
          }
        }
    }
    if(mn==1e9)return -1;
    return mn;
}
int main()
{
 int n,m;
 sff(n,m);
 while(m--)
 {
     int x,y,z;
     sfff(x,y,z);
     adj[x].pb({y,z});
     adj[y].pb({x,z});
 }
 int src,dest;
 sff(src,dest);
 pf("%d\n",bfs(src,dest));
    return 0;
}
/*
Ref:
*/


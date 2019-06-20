/*Never Give up*/
/*
Problem  :http://codeforces.com/contest/1106/problem/D
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
#define MAX 100005
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
vector<int>adj[MAX];
bool visited[MAX];
int nodes, edges, x, y, ck = 0;
void bfs(int s)
{
priority_queue <int, vector<int>, greater<int> > q;
   // priority_queue< int >q;
   // int visited[MAX]= {0};
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u=q.top();
   cout<<u<<" ";        q.pop();

        for(int l=0; l<adj[u].size(); l++)
        {
            int v = adj[u][l];

            if(visited[v]==false)
            {

                visited[v]=true;
            //    cout<<v<<" "<<visited[v]<<endl;
//                level[v] = level[u]+1;
                q.push(v);
            }
        }
    }
//   printf("%2d to %2d: %d\n", s, d, level[d]);
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
    bfs(1);
    return 0;
}


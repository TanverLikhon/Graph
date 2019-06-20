/*Never Give up*/
/*
Problem  :https://codeforces.com/problemset/problem/839/C
Verdict     :AC
Time         :93 ms	4700 KB
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
#define MAX    100005
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
vector<int>edge[MAX];
int n,m;
//int level[MAX;
int ck;
double sum=0;
void bfs()
{
    double level[n+1];
    bool visited[n+1];
    for(int i=1; i<=n; i++)level[i]=0.00,visited[i]=0;
    queue< int >q;
    visited[1]=1;
    level[1]=1.00;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        //  if(sz(edge[u])==1)ck++,sum+=level[u];
        //  else
        for(int l=0; l<sz(edge[u]); l++)
        {
            int v = edge[u][l];
            if(!visited[v])
            {
                visited[v]=1;
                if(u==1)
                level[v] = level[u]/(sz(edge[u])*1.0);
                else
                level[v]=level[u]/((sz(edge[u])-1)*1.0);
                q.push(v);
            }
        }

    }
    for(int i=1; i<=n; i++)
    sum+=level[i];
    pf("%.14f\n",sum-1);//subtracting 1 because node 1 is the
    //initial position of the horse

}
int main()
{
    sf(n);
    m=n-1;
    while(m--)
    {
        int x,y;
        sff(x,y);
        edge[x].pb(y);
        edge[y].pb(x);
    }
    bfs();

    return 0;
}
/*
Ref:https://codeforces.com/blog/entry/53815
https://en.wikipedia.org/wiki/Expected_value
*/

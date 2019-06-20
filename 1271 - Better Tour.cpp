/*Never Give up*/
/*
Problem  :http://lightoj.com/volume_showproblem.php?problem=1271
Verdict     :AC
Time         :.260s
Memory  :7980kB
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
#define MAX   50005
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
int src,dest,ck=1,M,N;
vi edge[MAX];

int parent[MAX];
void print(int i)
{
    if(i!=src)
        print(parent[i]);
        if(i!=dest)
    pf("%d ",i);
    else pf("%d\n",i);
}
void weightedbfs()
{

    queue<int>   q;
    bool  visited [N+1];
    for(int i=1;i<=N;i++)
    visited[i]=false,sort(edge[i].begin(),edge[i].end());
    visited[src]=true;
    q.push(src);
    while(!q.empty())
    {
        int x=q.front();if(x==dest)break;
        q.pop();
        for(int i=0; i<edge[x].size(); i++)
        {
            int m=edge[x][i];

            if(!visited[m])
            {
                visited[m]=true;
                q.push(m);
                parent[m]=x;
            }
        }
    }
    pf("Case %d:\n",ck++);
        print(dest);
   //     nl;
}

int main()
{
    int t;
    sf(t);
    while(t--)
    {
        sf(M);

        int x,y,z;
        sf(x),M--;
        src=x;
        N=max(N,x);
        while(M--)
        {

            sf(y);
            N=max(N,y);
            edge[x].pb(y);
            edge[y].pb(x);
            x=y;
        }
        dest=y;
        weightedbfs();
        for(int i=1; i<=N; i++)edge[i].clear(),parent[i]=i;
//        weight.clear();
    }

    return 0;
}

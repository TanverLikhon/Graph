/*Never Give up*/
/*
Problem  :https://codeforces.com/problemset/problem/1020/B
Verdict     :AC
Time         :31ms
Memory  :200KB
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
#define en        pf("Ente1d\n")
#define en1      pf("Enter1d\n")
#define MAX    1005
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
vi edge[MAX];
int n;
void solve(int x)
{
    bool visited[n+1];
    int ck[n+1];
    for(int i=1; i<=n; i++)visited[i]=false,ck[i]=0;

    //visited[x]=true,ck[i]++;
    queue<int >q;
    q.push(x);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(!visited[u])
        {

            visited[u]=true,ck[u]++;//en1;
          //if(ck[u]==2){pf("%d ",u);return;}
            for(int i=0; i<edge[u].sz; i++)
               { ck[edge[u][i]]++,q.push(edge[u][i]);//,en;
                 if(ck[edge[u][i]]>1){pf("%d ",edge[u][i]);return;}

               }
        }
    }
   // cout<<x<<"  -- ";
  // for(int i=1;i<=n;i++)if(ck[i]>2){pf("%d ",i);return;}
}
int main()
{

    sf(n);
    for(int i=1; i<=n; i++)
    {
        int x;
        sf(x);
        edge[i].pb(x);
    }
    for(int i=1; i<=n; i++)
    {
        solve(i);
    }
    return 0;
}
/*
Ref:
*/

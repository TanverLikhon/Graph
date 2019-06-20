/*Never Give up*/
/*
Problem  :http://lightoj.com/volume_showproblem.php?problem=1009
Verdict     :AC after trying 12hrs+ :)
Time         :0.190sec
Memory  :6676kB
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
#define MAX    100005
int N=-1;
int ck2,ck1;
vector<int>adj[MAX];
mp<int,vi>res;
int visited[MAX];
int c=1;
void bfs(int s)
{
    if(adj[s].size()==0)return;
    //cout<<"source "<<s<<endl;
    // cout<<"c  "<<ck1<<"  "<<ck2<<endl;
  /*for(int i=1; i<=N; i++)
      {
        cout<<i<<"--->";
        for(int j=0;j<adj[i].sz;j++)
        cout<<adj[i][j]<<"  ";nl;

      }
*/
    queue< int >q;
    // if(ck1>ck2&&)
    visited[s]=1;
    //  else visited[s]=2;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        // cout<<u<<"  u     ";
        if(visited[u]==1)ck1++;//cout<<"one ";
        else ck2++;//,cout<<"two ";nl;
        for(int l=0; l<adj[u].size(); l++)
        {
            int v = adj[u][l];
            if(visited[v]==0)
            {
                if(visited[u]==1)visited[v]=2;
                else if(visited[u]==2)visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
    res[s].pb(ck1);
    res[s].pb(ck2);
//   cout<<"Printing "<<endl;
    //for(int i=1; i<=N; i++)cout<<visited[i]<<"  ";
    //  cout<<ck1<<"  - "<<ck2<<endl;
}
int main()
{
    int t;
    sf(t);
    while(t--)
    {
        int n;
        sf(n);
        while(n--)
        {
            int x,y;
            sff(x,y);
            adj[x].pb(y),adj[y].pb(x);
            N=max(N,x);
            N=max(N,y);
        }
        int sum=0;
        for(int i=1; i<=N; i++)
            visited[i]=0;
        for(int i=1; i<=N; i++)
            if(visited[i]==0)ck1=0,ck2=0,bfs(i);
        for(int i=1; i<=N; i++)
            adj[i].clear();
        mp<int,vi>::iterator it=res.begin();
        while(it!=res.end())
        {
            int x=it->first;
            sum+=(max(res[x][0],res[x][1]));
            it++;
        }
     res.clear();
        pf("Case %d: %d\n",c++,sum);
        N=0,ck1=0,ck2=0;

    }
    return 0;
}



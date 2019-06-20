/*Never Give up*/
/*
Problem  :https://codeforces.com/problemset/problem/510/B
Verdict     :AC
Time         :30ms
Memory  :9000KB
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
#define MAX    55
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n,m;
char adj[MAX][MAX];
bool flag=false;
bool visited[MAX][MAX];
bool parent [MAX][MAX][MAX][MAX];
//mp<li,li>ck;
void dfs(int x,int y)
{
     //cout<<"track "<<x<<" "<<y<<endl;
    //if(visited[x][y]){flag=true;return ;}
    visited[x][y]=true;
    for(int i=0; i<4; i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&adj[xx][yy]==adj[x][y])
        {

            //   if(visited[xx][yy]){flag=true;return ;}
         if(!visited[xx][yy]&&parent[xx][yy][x][y]==false)
            parent[x][y][xx][yy]=true,dfs(xx,yy);
            else if(visited[xx][yy]&&parent[xx][yy][x][y]==false){flag=true;return;}
        }


    }

}
int main()
{
    sff(n,m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>adj[i][j];
  //  dfs(0,0);
      for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
         if(!visited[i][j]){
             if(flag)break;
             dfs(i,j);
         }
  /*  for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<visited[i][j]<<adj[i][j]<<"  ";
        }
        nl;
    }*/
    if(flag)pf("Yes\n");
    else pf("No\n");


    return 0;
}
/*
Ref:
*/

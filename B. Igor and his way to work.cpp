/*Never Give up*/
/*
Problem  :
Verdict     :AC
Time         :264 ms	16900 KB
Memory  :
*/
//learned direction count :)
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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char adj[1005][1005];
int n,m; bool flag=false;
int srcx,srcy,destx,desty;
bool visited[1005][1005][4][4];
void dfs(int x,int y,int dir,int mov)
{
 //   cout<<x<<"  "<<y<<"  "<<dir<<"  "<<mov<<"flag "<<flag<<endl;
    if(x<0||y<0||x>=n||y>=m)return;
    if(x==destx&&y==desty){flag=true;return;}
    if(adj[x][y]=='*'||visited[x][y][dir][mov]==true)return;
     visited[x][y][dir][mov]=1;
     for(int i=0;i<4;i++)
     {
         if(flag)break;
         int xx=x+dx[i];
         int yy=y+dy[i];
         if(i==dir)dfs(xx,yy,i,mov);
         else if(mov<2)dfs(xx,yy,i,mov+1);
     }

}
int main()
{
    sff(n,m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>adj[i][j];
            if(adj[i][j]=='S')
                srcx=i,srcy=j;
            else if(adj[i][j]=='T')
                destx=i,desty=j;
        }
    }
//cout<<srcx<<"  "<<srcy<<" "<<destx<<"   "<<desty<<endl;
   for(int i=0;i<4;i++)
   {
    /*   cout<<"i->"<<i<<endl;
       cout<<"flag "<<flag<<endl ;*/
       if(flag)break;
       int x=srcx+dx[i],y=srcy+dy[i];
       dfs(srcx+dx[i],srcy+dy[i],i,0);
   }

    if(flag)
        pf("YES\n");
    else
        pf("NO\n");
    return 0;
}

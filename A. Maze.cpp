/*Never Give up*/
/*
Problem  :http://codeforces.com/problemset/problem/377/A
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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

char adj[1000][1000];
bool visited[1000][1000];
int n,m,k;
int srcx=-1,srcy=-1,ck,ck1,rem;
void dfsVisit(int x,int y)
{
//cout<<adj[x][y];
    ck++;
    if(ck>rem)adj[x][y]='X';//,cout<<x<<"-"<<y<<endl;
  //  cout<<ck<<"  "<<rem<<endl;
    visited[x][y]=true;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            int xx=dx[i]+x;
            int yy=dy[i]+y;
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&visited[xx][yy]==false&&adj[xx][yy]=='.')
            {
                dfsVisit(xx,yy);
            }

        }
    }


}

int main()
{
    sfff(n,m,k);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>adj[i][j];
            if(adj[i][j]=='.')
            {
                ck++;
                if(srcx==-1&&srcy==-1)srcx=i,srcy=j;
            }
        }
    }//nl;nl;
    rem=ck-k;
    ck=0;
    dfsVisit(srcx,srcy);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<adj[i][j];
        }
        nl;
    }

    return 0;
}


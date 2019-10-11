/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2035
Verdict     :AC
Time         :0.00s
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
#define pf1(a)        pf("%d\n",a);
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
#define gcd(a,b) __gcd(a,b)
#define PI            acos(-1.0)

// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    21

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
char adj[MAX][MAX];
bool visited[MAX][MAX];
int m,n;
int srcx,srcy;
int ck=0;
char c;
bool isvalid(int x,int y)
{
    if(x<0||x>=m||y<0||y>=n)
        return false;
    return true;
}
void dfs(int x,int y)
{
    visited[x][y]=true;
    ck++;
    for(int i=0; i<4; i++)
    {
        int tmpx=x+dx[i];
        int tmpy=y+dy[i];
        if(tmpy<0)tmpy=n-1;
        if(isvalid(tmpx,tmpy))
        {
            if(!visited[tmpx][tmpy]&&adj[tmpx][tmpy]==c)
                dfs(tmpx,tmpy);
        }
    }
}
int main()
{
    faster
    while(cin>>m>>n)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                visited[i][j]=false;
                char ch;
                cin>>ch;
                adj[i][j]=ch;
            }
        }
        cin>>srcx>>srcy;
        c=adj[srcx][srcy];
        dfs(srcx,srcy);
        int mx=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j]&&adj[i][j]==c)
                {
                    ck=0;
                    dfs(i,j);
                    mx=max(mx,ck);
                }

//                if()
          //      cout<<"i "<< i<<"   j   "<<j<<endl;
      //          cout<<" CK "<<ck<<endl;
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
/*
Ref:

6 6
aaaaaa
bbaaab
aaaabb
abaaba
abbaaa
abbabb
5 5


*/



/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3057
Verdict     :AC
Time         :0.010s	278th
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
#define PI  acos(-1)
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

// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    105

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
int r,c,m,n,w,odd=0,even=0;
int dx[8],dy[8];
int adj[MAX][MAX];
int val[MAX][MAX];
bool isValid(int x,int y)
{
    if(x<0||x>=r||y<0||y>=c)return false;
    return true;
}
void initialize()
{
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            adj[i][j]=0,val[i][j]=0;
    if(m!=n)
    {

        dx[0]=m,   dx[1]=m,   dx[2]=n,   dx[3]=n,   dx[4]=-m,  dx[5]=-m,  dx[6]=-n,  dx[7]=-n;
        dy[0]=n,   dy[1]=-n,  dy[2]=m,   dy[3]=-m,  dy[4]=n,   dy[5]=-n,  dy[6]=m,  dy[7]=-m;
    }
    else
    {
        dx[0]=m,dy[0]=n;
        dx[1]=-m,dy[1]=n;
        dx[2]=m,dy[2]=-n;
        dx[3]=-m,dy[3]=-n;
    }


    odd=0,even=0;//en;
}
void dfs(int srcx,int srcy)
{
    //cout<<srcx<<"  vs  "<<srcy<<endl;
    adj[srcx][srcy]=1;
    int z;
    if(m==n)z=4;
    else z=8;
    if(m==0||n==0)
    {
        int tmp=max(m,n);

        int x,y;

        if(isValid(srcx+tmp,srcy))
        {

            if(adj[srcx+tmp][srcy]!=-1)
                val[srcx][srcy]++;//,cout<<"x  "<<x<<" "<<"y  "<<y<<endl;;
            if(adj[srcx+tmp][srcy]==0)
                dfs(srcx+tmp,srcy);

        }
        if(isValid(srcx-tmp,srcy))
        {
            if(adj[srcx-tmp][srcy]!=-1)
                val[srcx][srcy]++;//,cout<<"x  "<<x<<" "<<"y  "<<y<<endl;;
            if(adj[srcx-tmp][y]==0)
                dfs(srcx-tmp,srcy);

        }
        if(isValid(srcx,srcy+tmp))
        {
            if(adj[srcx][srcy+tmp]!=-1)
                val[srcx][srcy]++;//,cout<<"x  "<<x<<" "<<"y  "<<y<<endl;;
            if(adj[srcx][srcy+tmp]==0)
                dfs(srcx,srcy+tmp);

        }
        if(isValid(srcx,srcy-tmp))
        {
            if(adj[srcx][srcy-tmp]!=-1)
                val[srcx][srcy]++;//,cout<<"x  "<<x<<" "<<"y  "<<y<<endl;;
            if(adj[srcx][srcy-tmp]==0)
                dfs(srcx,srcy-tmp);

        }



    }
    else
        for(int i=0; i<z; i++)
        {
            int x= srcx+dx[i];
            int y=srcy+dy[i];
            if(isValid(x,y))
            {
                if(adj[x][y]!=-1)
                    val[srcx][srcy]++;//,cout<<"x  "<<x<<" "<<"y  "<<y<<endl;;
                if(adj[x][y]==0)
                    dfs(x,y);

            }

        }

    if(val[srcx][srcy]%2)odd++;
    else even++;
    // cout<<val[srcx][srcy]<<endl;

}
int main()
{
    int t;
    sf(t);
    int k=1;
    while(t--)
    {
        sfff(r,c,m);
        sf(n);
        sf(w);
        initialize();
        for(int i=0; i<w; i++)
        {
            int x,y;
            sff(x,y);
            adj[x][y]=-1;
        }
        if(adj[0][0]!=-1)dfs(0,0);
        pf("Case %d: %d %d\n",k++,even,odd);
        // cout<<"odd "<<odd<<" even  "<<even<<endl;


    }



    return 0;
}
/*
Ref:
2
3 3 2 1
0
4 4 1 2
2
3 3
1 1


1
9 9 3 3
0

*/

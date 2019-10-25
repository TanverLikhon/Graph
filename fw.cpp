/*Never Give up*/
/*
Problem  :
Verdict     :
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


//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
#define MAX 10001
int graph[MAX][MAX];
ll dist[MAX][MAX];
int n,m;
void fw()
{
    int  i, j, k;
    for (k = 1; k <=n; k++)
    {
        for (i = 1; i <=n; i++)
        {
            for (j = 1; j <=n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    cout<<"Printing distances "<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            pf("%12d ",dist[i][j]);
        nl;

    }
}
int main()
{
    sff(n,m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i!=j)
                graph[i][j]=INT_MAX;
            else
                graph[i][j]=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=INT_MAX;
    for(int i=1; i<=m; i++)
    {
        ll x,y,z;
        slll(x,y,z);
        dist[x][y]=z;//int(pow(2,z));
        dist[y][x]=z;//int (pow(2,z));
    }

       cout<<"Printing distances "<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            pf("%12d   ",dist[i][j]);
        nl;

    }
    fw();

    return 0;
}
/*
Ref:
*/



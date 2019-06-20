/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=762
Verdict     :AC-717rank
Time         :.050sec
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
#define pf1        pf("%d\n");
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

#define MAX    101

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
int maxx=-1,c=1;
int edge[MAX][MAX];

void floydWarshall (int ck1)
{
    int dist[maxx+1][maxx+1], i, j, k;
    for (i = 1; i <=maxx; i++)
        for (j = 1; j <= maxx; j++)
            dist[i][j] = edge[i][j];

    for (k = 1; k <= maxx; k++)
    {
        for (i = 1; i <=maxx; i++)
        {
            for (j = 1; j <=maxx; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

            }
        }
    }

    int sum=0;
    for(int i=1; i<=maxx; i++)
    {
        for(int j=1; j<=maxx; j++)
        {
            if(dist[i][j]!=1000)
                sum+=dist[i][j];



        }
    }
    double res=sum/(ck1*(ck1-1)*1.0);
    pf("Case %d: average length between pages = %.3f clicks\n",c++,res);
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    { if(a==0&&b==0)break;
        maxx=-1; int ck1=0;
        mp<int,bool>ck;
        if(ck[a]==false)ck[a]=true,ck1++;
        if(ck[b]==false)ck[b]=true,ck1++;
        for(int i=1; i<=MAX; i++)
            for(int j=1; j<=MAX; j++)
            {
                if(i!=j)
                    edge[i][j]=1000;
            }
        edge[a][b]=1;
        maxx=max(maxx,max(a,b));
        while(sff(a,b)&&a&&b)
        {
            edge[a][b]=1;
            maxx=max(maxx,max(a,b));
            if(ck[a]==false)ck1++,ck[a]=true;
            if(ck[b]==false)ck1++,ck[b]=true;
        }
        floydWarshall(ck1);
    }

    return 0;
}
/*
Ref:
*/

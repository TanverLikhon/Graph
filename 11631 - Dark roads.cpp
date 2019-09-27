/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2678
Verdict     :AC
Time         :0.17sec
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

// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    200000

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
int n,m,idx[MAX];
pair<ll,pi > edge[MAX];
void initialize()
{
    for(int i=1; i<=n; i++)idx[i]=i;
}
int root(int x)
{
   while(idx[x]!=x)
   {
     idx[x]=idx[idx[x]];
     x=idx[x];
   }
   return x;
}

ll kruskal()
{

    int x,y;
    ll cost, minimumCost = 0;
    for(int i = 0;i < m;i++)
    {
        x = edge[i].ss.ff;
        y = edge[i].ss.ss;
        cost = edge[i].ff;
int r1=root(x),r2=root(y);
      if(r1!=r2)
        {
            minimumCost += cost;
            idx[r1]=idx[r2];
          //  union1(x, y);
        }
    }
    return minimumCost;

}


int main()
{

    while(sff(n,m))
    {
    if(n==0&&m==0)break;
        ll sum=0;
        int x,y,z;initialize();
        for(int i=0; i<m; i++)
        {
            sfff(x,y,z);
            edge[i]= {z,{x,y}};
        //    edge[i]= {z,{y,x}};
            sum+=z;

        }
        sort(edge,edge+m);
       // cout<<kruskal()<<endl;


        pf("%lld\n",sum-kruskal());

    }



    return 0;
}

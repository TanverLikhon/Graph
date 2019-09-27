/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=499
Verdict     :AC
Time         :0.010
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

#define MAX    1000

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48

int node,edge;
bool BellmanFord(int graph[][3],int src)
{
    int dis[node];bool flag=false;
    for (int i = 0; i < node; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;
    for (int i = 0; i < node - 1; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            if (dis[graph[j][0]] + graph[j][2] <
                    dis[graph[j][1]])
                dis[graph[j][1]] =
                    dis[graph[j][0]] + graph[j][2];
        }
    }
    for (int i = 0; i < edge; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX &&
                dis[x] + weight < dis[y])//break;
     return true;
     }
   //  cout<<"Printing distance"<<endl;
        //    for(int i=0;i<node;i++)
        //    cout<<i<<"--->"<<dis[i]<<endl;
    return false;
}
int main()
{
    int t;
    sf(t);
    while(t--)
    {
        int n,e;
        sff(n,e);
        node=n,edge=e;
        int graph[e][3];
        for(int i=0; i<e; i++)
        {

            int u,v,w;
            sfff(u,v,w);
            graph[i][0]=u;
            graph[i][1]=v;
            graph[i][2]=w;

        }
        int src=0;
        //sf(src);
        if(BellmanFord(graph,src))
        pf("possible\n");
        else pf("not possible\n");


    }


    return 0;
}
/*
Ref:
2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60


1
6 10
3 0 119
1 4 -267
3 1 232
5 0 -87
3 2 466
0 2 -172
0 4 18
1 5 537
3 5 -307
0 3 844

*/


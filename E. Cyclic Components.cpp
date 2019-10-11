/*Never Give up*/
/*
Problem  :https://codeforces.com/contest/977/problem/E
Verdict     :AC
Time         :186 ms	16000 KB
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

#define MAX    200005

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
int node,edge;
vi adj[MAX];
bool visited[MAX];
int track,ck,c=1;
int sT[MAX];
bool f=false;


void dfs(int src)
{
    visited[src]=true;
    if(sz(adj[src])!=2) return;
    sT[src]=c++;
    for(int i=0; i<sz(adj[src]); i++)
    {
        int x=adj[src][i];
        int tt=0;
        //    cout<<" x  =  "<<x<<"   track  "<<track<<endl;
        //   cout<< "st src "<<sT[src]<<"     st child  "<<sT[x]<<endl;
//cout<<" diff "<<sT[]
        if(!visited[x])
            dfs(x);
        else if(visited[x]&&sT[src]-sT[x]>=2&&x==track&&sz(adj[x])==2&&sz(adj[src])==2)
        {
       //     tt=1;
            ck++;

            //      cout<<src<<"      "<<x<<"      track "<<track<<endl;
        }


    }
    if(src!=track)
        c--;

    //cout<<"exit src "<<src<<endl;
}
int main()
{
    sff(node,edge);
    for(int i=0; i<edge; i++)
    {
        int x,y;
        sff(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
        //cc[{x,y}]=true;
        // cc[{y,x}]=true;
    }
    for(int i=1; i<=node; i++)
        if(!visited[i])
        {
            f=false;
            c=1;
            track=i;
            dfs(i);
        }
    pf1(ck);


    return 0;
}
/*
Ref:
5 4
1 2
3 4
5 4
3 5

17 15
1 8
1 12
5 11
11 9
9 15
15 5
4 13
3 13
4 3
10 16
7 10
16 7
14 3
14 4
17 6



*/

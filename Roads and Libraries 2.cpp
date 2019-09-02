/*Never Give up*/
/*
Problem  :https://www.hackerrank.com/challenges/torque-and-development/problem
Verdict     :AC
Time         :991ms
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

#define MAX    100002

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
vector <int> adj[MAX];
bool visited[MAX];
ll nodes, edges,ck=0;
void dfs(int s)
{
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
            ck++;
        }
    }
}

void initialize()
{
    for(int i=1; i<=nodes; i++)visited[i]=false,adj[i].clear();
}
int main()
{
    int q;
    sf(q);
    while(q--)
    {
        ll n,m,lib,road;
        slll(nodes,edges,lib);
        sl(road);
        for(int i=0; i<edges; i++)
        {
            int x,y;
            sff(x,y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        if(lib<=road)pf("%lld\n",nodes*lib);
        else
        {
            ll sum=0;
            int r=0,l=0;
            for(int i=1; i<=nodes; i++)
            {
                if(!visited[i])
                {
                    l++;
                    dfs(i);
                    sum+=ck;
                  //  cout<<"Ck "<<ck<<endl;
                    ck=0;

                }
            }
          //  cout<<"Sum "<<q<<endl;
            pf("%lld\n",lib*l+sum*road);

        }
        initialize();

    }



    return 0;
}
/*
Ref:
1
2 1 3 4
1 2

5
9 2 91 84
8 2
2 9
5 9 92 23
2 1
5 3
5 1
3 4
3 1
5 4
4 1
5 2
4 2
8 3 10 55
6 4
3 2
7 1
1 0 5 3
2 0 102 1


*/

/*Never Give up*/
/*
Problem  :https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2870
Verdict     :AC
Time         :0.04s 107 th
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

#define MAX    100005

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
vector <int> adj[MAX];

bool visited[MAX];
int nodes, edges, ck = 0;
stack<int> st;
bool flag=false;
void dfs(int s)
{

    visited[s] = true;

    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
            //ck++;
        }
    }

    st.push(s);
}

void initialize()
{
    for(int i=1; i<=nodes; i++)
        visited[i]=false;
}

int main()
{
    // faster
    int t;
    // cin>>t;
    sf(t);int cc=1;
    while(t--)
    {
        flag=false;
        // cin>>nodes>>edges;
        sff(nodes,edges);
        for(int i=0; i<edges; i++)
        {
            int x,y;
            //  cin>>x>>y;
            sff(x,y);
            adj[x].pb(y);
            //  adj1[y].pb(x);
        }
        for(int i=1; i<=nodes; i++)
            if(!visited[i])
                dfs(i);
        initialize();
        ck=0;
        flag=true;
        while(!st.empty())
        {
            int tt=st.top();
            st.pop();
            if(!visited[tt])
                dfs(tt),ck++;//,en;

        }
        initialize();
       pf("Case %d: %d\n",cc++,ck);
        // cout<<ck<<endl;
        for(int i=1; i<=nodes; i++)
            adj[i].clear();

    }



    return 0;
}
/*
Ref:
1
4 2
2 1
4 1
*/



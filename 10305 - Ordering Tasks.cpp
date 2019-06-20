/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1246
Verdict     :AC
Time         :0.000
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
#define MAX  102
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
vector <int> adj[MAX];
bool visited[MAX];
int nodes, edges;
vi st;
void dfs(int s)
{
    // cout<<s<<endl;
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
        }
    }
    st.pb(s);
}
void initialize()
{
    for(int i=1; i<=nodes; i++)
        visited[i]=false;
}
int main()
{
    while(sff(nodes,edges))
    {
        if(nodes==0&&edges==0)
            break;
        for(int i = 0; i < edges; ++i)
        {
            int x,y;
            sff(x,y);
            adj[x].pb(y);
        }
        initialize();
        for(int i = 1; i <=nodes; ++i)
        {
            if(visited[i] == false)
            {
                dfs(i);
            }
        }
        // cout<<"Printing discovering and finishing time "<<endl;
        // for(int i=0; i<nodes; i++)
//            cout<<"Node  "<<i<<" :: "<<dTime[i]<<" -> "<<fTime[i]<<endl;
        //  cout<<"Topological sort :  ";
        for(int i=st.sz-1; i>=0; i--)
        {
            pf("%d",st[i]);
            if(i)
                pf(" ");
        }
        nl;st.clear();
        for(int i=1; i<=nodes; i++)
            adj[i].clear();
    }

    return 0;
}

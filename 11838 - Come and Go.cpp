/*Never Give up*/
/*
Problem  :https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2938
Verdict     :AC
Time         :0.2S 634th
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
#define sp  ' '
// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    2005

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
vector <int> adj[MAX];
vector <int> adjrev[MAX];

bool visited[MAX];
int nodes, edges, ck = 0;
stack<int> st;

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
vi track;
void dfs1(int s)
{
    track.pb(s);
    visited[s] = true;

    for(int i = 0; i < adjrev[s].size(); ++i)
    {
        // cout<<"child  "<<idx[s]<<endl;

        if(visited[adjrev[s][i]] == false)
        {

            dfs1(adjrev[s][i]);
            //ck++;
        }
    }


}

void initialize()
{
    for(int i=1; i<=nodes; i++)
        visited[i]=false;
}
int main()
{

    faster

    while(cin>>nodes>>edges)
    {
        if(nodes==0&&edges==0)
            return 0;
        int k=0;
        for(int i=0; i<edges; i++)
        {
            int x,y,c;
            cin>>x>>y>>c;
            if(c==1)
                adj[x].pb(y),adjrev[y].pb(x);
            else
            {
                adj[x].pb(y);
                adj[y].pb(x);

                adjrev[x].pb(y);
                adjrev[y].pb(x);



            }


        }
        initialize();
        //cout<<"K "<<k<<endl;
        for(int i=1; i<=nodes; i++)
        {
            if(!visited[i])
                dfs(i);
        }
        initialize();
        bool flag=true;
        while(!st.empty())
        {
            int xx=st.top();
            st.pop();
            if(!visited[xx]&&flag)
            {
                dfs1(xx);
                k++;
                if(k>1)
                {
                    flag=false;
                   // break;
                }
            }


        }
        cout<<flag<<endl;
        for(int i=1; i<=nodes; i++)
            adj[i].clear(),adjrev[i].clear();

    }



    return 0;
}
/*
Ref:
*/

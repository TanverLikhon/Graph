/*Never Give up*/
/*
Problem  :https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2756
Verdict     :AC
Time         :.22sec 150r
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

#define MAX    1005

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
mp<string,int>id;
mp<int,string>idx;
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
//vi track;
void dfs1(int s)
{
//    track.pb(s);
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
    int cc=1;
    while(cin>>nodes>>edges)
    {
        if(nodes==0&&edges==0)
            return 0;
  cin.ignore();
      //  getchar();
        for(int i=1; i<=nodes; i++)
        {
            string str;


            getline(cin,str);
            //cin.ignore();

            id[str]=i;
            idx[i]=str;
        }

        //    for(int i=1; i<=nodes; i++)
        //      cout<<idx[i]<<endl;




        for(int i=0; i<edges; i++)
        {
            string str,str1;
           // cin.ignore();
            //getchar();
            getline(cin,str);
            // cin.ignore();

          //  cin.ignore();
            // getchar();
            getline(cin,str1);
            // cin.ignore();

            adj[id[str]].pb(id[str1]);
            adjrev[id[str1]].pb(id[str]);


        }
        initialize();
        //cout<<"K "<<k<<endl;
        for(int i=1; i<=nodes; i++)
        {
            if(!visited[i])
                dfs(i);
        }
        initialize();
        ck=0;
        while(!st.empty())
        {
            int xx=st.top();
            st.pop();
            //cout<<xx<<endl;
            if(!visited[xx])
            {
                dfs1(xx);
                ck++;

            }


        }
        pf1(ck);
        for(int i=1; i<=nodes; i++)
            adj[i].clear(),adjrev[i].clear();
        id.clear();
        idx.clear();

    }



    return 0;
}
/*
Ref:
*/

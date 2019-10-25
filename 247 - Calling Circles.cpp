/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=183
Verdict     :AC
Time         :0S 503th
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

#define MAX    27

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
    int cc=1;
    while(cin>>nodes>>edges)
    {
        if(nodes==0&&edges==0)
            return 0;
        int k=1;
        for(int i=0; i<edges; i++)
        {
            string str,str1;
            cin>>str>>str1;
            int x,y;
            if(id[str])
            {

                x=id[str];
            }
            else
            {
                id[str]=k++;
                x=id[str];
                idx[x]=str;

            }
            if(id[str1])
            {
                y=id[str1];
            }
            else
            {
                id[str1]=k++;
                y=id[str1];
                idx[y]=str1;

            }
            adj[x].pb(y);
            adjrev[y].pb(x);

        }
        initialize();
        //cout<<"K "<<k<<endl;
        for(int i=1; i<k; i++)
        {
            if(!visited[i])
                dfs(i);
        }
        initialize();

        if(cc!=1)
            cout<<endl;
        cout<<"Calling circles for data set "<<cc++<<":"<<endl;
        while(!st.empty())
        {
            int xx=st.top();
            st.pop();
            if(!visited[xx])
            {
                dfs1(xx);
                for(int i=0; i<sz(track)-1; i++)
                {
                    cout<<idx[track[i]]<<", ";
                }
                cout<<idx[track[sz(track)-1]]<<endl;
                track.clear();
            }


        }
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

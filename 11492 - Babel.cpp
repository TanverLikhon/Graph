
/*Never Give up*/
/*
Problem  :https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2487
Verdict     :AC
Time         :0.000
Memory  :RANK 194
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
#define vp vector<pi>
#define mp         map
#define nl         printf("\n")
#define en        pf("Entered\n")
#define en1      pf("Entered 2\n")
#define gcd(a,b) __gcd(a,b)
///should print
// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    100006

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
mp<string,int>kk;
vp adj[MAX];
vi letter[MAX];
int dist[MAX][26];
class node
{
public:
    int name;
    int cost;
    int index;
    node() {}
    node(int n,int c,int d)
    {
        name=n;
        cost=c;
        index=d;
    }
};
bool operator<(node a,node b)
{
    if(a.index==b.index)
        return false;
    return b.cost<a.cost;
}
int n;
void bfs()
{
    priority_queue<node>q;
    int mn=1e9;
    node tmp(1,0,-1);
    q.push(tmp);
    for(int i=1; i<=n; i++)
    {
        fill(dist[i],dist[i]+26,1e9);
    }
    int tp;
    while(!q.empty())
    {
        node u=q.top();
        q.pop();
        int x= u.name;
        int w=u.cost;
        for(int i=0; i<sz(adj[x]); i++)
        {

            int ch=adj[x][i].ff;
            int cw=adj[x][i].ss;
            int l=letter[x][i];

            if(u.index!=l&&dist[ch][l]>u.cost+cw)
            {
                dist[ch][l]=u.cost+cw;
                node t(ch,dist[ch][l],l);
                q.push(t);
            }
        }
    }
    for (int i = 0; i < 26; i++)
        mn = min(mn, dist[2][i]);
    if (mn >= 1e9)
        puts("impossivel");
    else
        printf("%d\n", mn);
    for(int i=1; i<n; i++)
        adj[i].clear(),letter[i].clear();
}
int main()
{
    int m;
    while(sf(m))
    {
        if(m==0)
            return 0;
        int k=3;
        string src,dest;
        cin>>src>>dest;
        kk[src]=1,kk[dest]=2;
        while(m--)
        {
            string str1,str2,str3;
            cin>>str1>>str2>>str3;
            if(kk[str1]==0)
                kk[str1]=k++;
            if(kk[str2]==0)
                kk[str2]=k++;
            adj[kk[str1]].pb({kk[str2],sz(str3)});
            adj[kk[str2]].pb({kk[str1],sz(str3)});
            letter[kk[str1]].pb(str3[0]-97);
            letter[kk[str2]].pb(str3[0]-97);
        }
        n=k;
        bfs();
        k=0;
        kk.clear();
    }
    return 0;
}
/*
3penalties
Ref:penalty case
21
i l
m j kvov
b s iuetuhcitvpcxjgz
x r hcgqhqnvn
q w marjkvrfqihnrqp
q h xlppshfpwvfsuuunde

l w dftt

w j pqrmb
i e pjkl
g s cmzqpednpgsk
z r hilyuoga
j x uk
s m uarmrxpemw
z x qsfyefuuoxeliawamnvo
e h bzjqvipu
a h anfxitumgeoefcscqy
l v keshphcpodseipm
d l mpoqwqkyglkdnwh
f g oioelgiwxubiunz
k g c

q w dilqfvxltlv

j q ryeotgypvycbweu
*/

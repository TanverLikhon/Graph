/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2001
Verdict     :AC
Time         :0.000sec
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
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define vi           vector<int>
#define vl           vector<ll>
#define vs           vector<string>
#define li            list<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define mp         map
#define nl         printf("\n")
#define en        pf("Entered\n")
#define en1      pf("Entered 2\n")

#define MAX    100000

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
vi edge[MAX];
mp<string,int >gp;
mp<int,string >gp1;

bool visited[MAX];
int nodes, edges;
vs st;
vi st1;
vector<int >cc;
int d[MAX];
mp<int,bool>dc;

void initialize()
{
    for(int i=0; i<nodes; i++)
        visited[i]=false,edge[i].clear(),d[i]=0;
        st.clear();
        gp.clear();
        gp1.clear();
        dc.clear();


}


int main()
{
    int n,ck=1,m,x,y;
    string str,str1;
    while(sf(nodes)!=EOF)
{

        for(int i=0; i<nodes; i++)
        {
            cin>>str;
            gp[str]=i;
            gp1[i]=str;
        }
        sf(m);
        edges=m;
        while(m--)
        {
            cin>>str>>str1;
            x=gp[str],y=gp[str1];
            edge[x].pb(y);
            d[y]++;
        }
        for(int i=0;i<nodes;i++)
        {
          for(int j=0;j<nodes;j++)
          {
             if(d[j]==0&&dc[j]==0)
             {
               dc[j]=1;st.pb(gp1[j]);
               for(int k=0;k<sz(edge[j]);k++)
               d[edge[j][k]]--;
               break;
             }

          }
        }
        pf("Case #%d: Dilbert should drink beverages in this order:",ck++);
      /*  for(int i=0;i<sz(st1);i++)
        cout<<" "<<gp1[st1[i]];
        cout<<"second half"<<endl;*/
        for(int i=0;i<nodes;i++)
        cout<<" "<<st[i];
pf(".");        nl;nl;
        initialize();



    }
    return 0;
}
/*
Ref:suvro vai
*/

/*Never Give up*/
/*
Problem  :https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3873
Verdict     :AC
Time         :0.060s  274th
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

// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    50003

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
vector <int> adj[MAX];
bool visited[MAX];
int dist[MAX];
int nodes, edges, x, y, ck=1,c=0; ;
int sT[MAX],fT[MAX],track;
int tmp,tmp1,tmp2,tmp3;
bool f1,f2,f3;
void dfs(int s)
{
 // cout<<"Source : "<<s<<endl;
    sT[s]=ck;
    c++,ck++;
    visited[s]=true;
    for(int i = 0; i < adj[s].size(); ++i)
    {
        int child=adj[s][i];
        if(visited[child] == false)
        {
            dfs(child);
        }
        else if(visited[child]&&child==track)
        {
            f1=true;
        }
        else if(visited[child]&&child!=track&&dist[child]==0)
        {
            tmp=child;
            f2=true;
            tmp2=c-sT[child]+1;
            tmp1=sT[child];

        }
        else if(visited[child])
        {
         //   cout<<"child "<<child <<"dist "<<dist[child]<<endl;
           // dist[s]+=dist[child];
           track=dist[child];f3=true;
//cout<<"dist final "<<dist[child]<<endl;
        }
    }
    fT[s]=ck;
    ck++;
  //  cout<<fT[s]<<"---"<<sT[s]<<endl;
 //   cout<<"before "<<dist[s]<<endl;
    dist[s]+=(fT[s]-sT[s]+1)/2;
    if(f3)dist[s]+=track;
  //  cout<<"after "<<dist[s]<<endl;
    if(f1)
        dist[s]=c;
    if(f2)
    {
        if(sT[s]>=tmp1)
            dist[s]=tmp2;//,en;
    }
}

void initialize()
{
    for(int i=1; i<=nodes; i++)
        visited[i]=false,dist[i]=0;
}

int main()
{
    int t;
    sf(t);
    int k=1;
    while(t--)
    {
        int mx=-1,mn=INT_MAX;
        sf(edges);
        nodes=edges;
        initialize();
        for(int i=0; i<edges; i++)
        {
            sff(x,y);
            adj[x].pb(y);

        }

        nodes=edges;
        int vis=-1,idx=INT_MAX;
        for(int i=1; i<=edges; i++)
        {
            ck=1,c=0;f1=false,f2=false,f3=false;
            if(visited[i]==false)
            {
                track=i;
                dfs(i);
            }
            if(dist[i]>=vis)
            {
                if(dist[i]==vis)
                    idx=min(idx,i);
                else
                    vis=dist[i],idx=i;
            }

        }



      pf("Case %d: %d\n",k++,idx);
        for(int i=1; i<=edges; i++)
          //cout<<i<<"----"<<dist[i]<<endl,adj[i].clear();
      adj[i].clear();
    }


    return 0;
}
/*

3
3
1 2
2 3
3 1
4
1 2
2 1
4 3
3 2
5
1 2
2 1
5 3
3 4
4 5

1
7
5 4
3 4
4 6
6 7
7 1
1 2
2 1

1
5
1 2
2 3
3 4
4 5
4 2

1
6
5 6
6 3
3 2
2 1
1 3
4 1


*/

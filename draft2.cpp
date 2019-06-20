/*Never Give up*/
/*
Problem  :
Verdict     :
Time         :
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

#define MAX    100000

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48

int n;
int dis[30];
int dis1[30];
mp<pi,int>weight;
mp<pi,bool>young;
vi adj[100];
bool flag=false;
void bfs(int src)
{
    bool visited[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    visited[src]=true;
    if(flag==false)
        dis[src]=0;
    else
        dis1[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int x=q.front();

        q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            int tmp=adj[x][i];

            if(visited[tmp]==false)
            {
                visited[tmp]=true;
                if(flag==false)
                    dis[tmp]=dis[x]+1;
                else
                    dis1[tmp]=dis1[x]+1;
                q.push(tmp);
            }

        }

    }

}
int main()
{
    int t;
    sf(t);
    int ck=1;
    while(t--)
    {
        int src,dest,x,xy;
        sf(x);
        char ch1,ch2,ch3,ch4;
        while(x--)
        {
            cin>>ch1>>ch2>>ch3>>ch4>>xy;
            int a,b,c,d;
            a=int(ch3)-65,b=int(ch4)-65;
            weight[{a,b}]=xy;
            if(ch1=='Y')
            {
              young[{a,b}]=true;
              if(ch2=='B')young[{a,b}]=true,weight[{a,b}]=xy;

            }
            else
            {
              young[{a,b}]=false;
              if(ch2=='B')young[{a,b}]=false,weight[{a,b}]=xy;
            }


        }

    }
    return 0;
}

/*
Ref:
*/

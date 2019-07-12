/*Never Give up*/
/*
Problem  :https://www.hackerrank.com/challenges/journey-to-the-moon/problem
Verdict     :AC
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
vi arr;
int nodes, edges, x, y,ck=0;
void dfs(int s)
{
    ck++;
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
        }
    }

}
int main()
{
    sff(nodes,edges);
    for(int i=0; i<edges; i++)
    {
        sff(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if(nodes==1)
    {
        pf("0\n");
        return 0;
    }
    int xx=0;
    for(int i=0; i<nodes; i++)
    {
        if (!visited[i])
        {
            xx++;
            dfs(i);
            arr.pb(ck);
            ck=0;
        }
    }
    if(xx==1){pf("0\n");return 0;}
    ll sum=arr[0]*arr[1];
    int arr1[xx+1];
    arr1[0]=arr[0];
  //  cout<<"Printing frequencey"<<sz(arr)<<endl;
    //for(int i=0;i<sz(arr);i++)
     //   cout<<arr[i]<<"    ";

//cout<<sum<<endl;

    for(int i=1; i<sz(arr); i++)
    {
        //cout<<arr[i]<<"  ";
        arr1[i]=arr1[i-1]+arr[i];
    }
   //cout<<sum<<endl;
    for(int i=1; i<xx-1; i++)
        //   cout<<"Arr1 "<<arr1[i]<<"    "<<arr[i+1]<<endl;
        sum+=(arr1[i]*arr[i+1]);
    pf("%lld\n",sum);
    return 0;
}
/*
penalty case
10 20
0 1
0 3
0 4
1 2
1 3
1 5
1 7
1 8
1 9
2 8
2 7
3 5
3 8
3 7
4 9
4 5
4 6
4 7
6 8
6 7
*/

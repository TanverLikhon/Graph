/*Never Give up*/
/*
Problem  :https://codeforces.com/contest/292/problem/B
Verdict     :AC
Time         :124 ms	3400 KB
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
#define li            list<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define mp         map
#define nl         printf("\n")
#define en        pf("Entered\n")
#define en1      pf("Entered 2\n")

#define MAX    100006

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48

int main()
{
int n,m;
sff(n,m);
vi edge[n+1];//globally declare korle time 154ms
while(m--)
{
 int x,y;
 sff(x,y);
 edge[x].pb(y);
 edge[y].pb(x);
}
int one=0,two=0,others=0;
for(int i=1;i<=n;i++)
 if(sz(edge[i])==1)one++;
 else if(sz(edge[i])==2)two++;
 else if(sz(edge[i])==n-1)others++;

 if(one==2&&two==n-2)pf("bus topology\n");
 else if(two==n)pf("ring topology\n");
 else if(others==1&&one==n-1)pf("star topology\n");
 else pf("unknown topology\n");

return 0;
}
/*
Ref:
*/

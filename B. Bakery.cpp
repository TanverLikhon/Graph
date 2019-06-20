/*Never Give up*/
/*
Problem  :https://codeforces.com/problemset/problem/707/B
Verdict     :AC
Time         :155 ms	8100 KB
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
#define en        pf("Ente1d\n")
#define en1      pf("Enter1d\n")
#define MAX      100005
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
mp<pi,int>weight;
bool ck[MAX];
int n,m,k;
void solve()
{
  int minn=INT_MAX;
  mp<pi,int>::iterator it=weight.begin();
  while(it!=weight.end())
  {
     int ff=it->first.first;int ss=it->first.second;
    // cout<<ff<<"   ----  "<<ss<<"-----"<<it->second<<endl;
    if(it->second>0)
    {
         if(ck[ff]&&ck[ss]==false)
     minn=min(minn,it->second);
     else if(ck[ff]==false&&ck[ss])
     minn=min(minn,it->second);
    }

  //   if(minn==0)
  //   cout<<"found   "<<ff<<"   "<<ss<<endl;
  it++;
  }
  if(minn!=INT_MAX)pf("%d\n",minn);
  else pf("-1\n");
}
int main()
{
    sfff(n,m,k);
    for(int i=0; i<m; i++)
    {
        int x,y,z;
        sfff(x,y,z);
       // cout<<weight[{x,y}]<<"   k  "<<endl;
        if(weight[ {x,y}]!=0)
            weight[ {x,y}]=min( weight[ {x,y}],z);
        else weight[ {x,y}]=z;
        if(weight[ {y,x}]!=0)
            weight[ {y,x}]=min( weight[ {y,z}],z);
        else weight[ {y,x}]=z;
    }
    for(int i=1;i<=k;i++)
    {
     int x;sf(x);
     ck[x]=true;
    }
    if(k==0||n==k){pf("-1\n");return 0;}
  solve();
    return 0;
}
/*
Ref:
*/

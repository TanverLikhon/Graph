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

#define MAX    100005

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
int n,q;
int arr[MAX];
int tree[3*MAX];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int m=(b+e)/2;
    init(l,b,m);
    init(r,m+1,e);
    tree[node]=max(tree[l],tree[r]);

}
int query(int node,int b,int e ,int i,int j)
{
  if(i>e||j<b)return -200000;
  if(b>=i&&e<=j)return tree[node];
  int left=node*2;
  int right=node*2+1;
  int mid = (b+e)/2;
  int x=query(left,b,mid,i,j);
  int y=query(right,mid+1,e,i,j);
  return max(x,y);


}
int main()
{
    faster
    while(cin>>n)
    {
        if(!n)
            break;
        cin>>q;
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
        }
        init(1,1,n);
        while(q--)
        {
         int x,y;
         cin>>x>>y;
         cout<<query(1,1,n,x,y)<<endl;
        }



    }
    return 0;
}
/*
Ref:
*/

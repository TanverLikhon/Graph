/*Never Give up*/
/*
Problem  :https://codeforces.com/contest/1234/problem/D
Verdict     :AC
Time         :842 ms	32000 KB
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

#define MAX    300001

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
string str;
int tree[MAX][27];
void build(int node,int left,int right)
{

    if(left==right)
    {
        int tmp=str[left]-'a';
        tree[node][tmp]++;
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int m=(left+right)/2;
    build(l,left,m);
    build(r,m+1,right);
    for(int i=0; i<26; i++)
        tree[node][i]=tree[l][i]+tree[r][i];
}
int query(int node,int left,int right,int i,int j,int c)
{
    //en;
    if(j<left||right<i)
        return 0;
    if(i<=left&&j>=right)
        return tree[node][c];

    int l=node*2;
    int r=node*2+1;
    int m=(left+right)/2;
    return query(l,left,m,i,j,c)+query(r,m+1,right,i,j,c);




}
void update(int node,int left,int right,int idx,int c)
{
    if(left==right&&left==idx)
    {
        int tmp=str[left]-'a';
        tree[node][tmp]--;
        str[left]=c+'a';
        tree[node][c]++;
        return;
    }
    int m=(left+right)/2;
    int l=node*2;
    int r=node*2+1;
    if(idx<=m)
        update(l,left,m,idx,c);
    else
        update(r,m+1,right,idx,c);

    for(int i=0; i<26; i++)
        tree[node][i]=tree[l][i]+tree[r][i];

}
int main()
{
    faster
    cin>>str;
    int q;
    cin>>q;
    build(1,0,str.size()-1);
    while(q--)
    {
        int aa;
        cin>>aa;

        if(aa==1)
        {
            int x;
            char ch;
            cin>>x>>ch;
            int tmp=ch-'a';
            update(1,0,str.size()-1,x-1,tmp);
            //cout<<"NEW = "<<str<<endl;
        }
        else
        {
            int a,l,r;
            cin>>l>>r;

            int ck=0;
            for(int i=0; i<26; i++)
            {
                int ans=0;
                ans=query(1,0,str.size()-1,l-1,r-1,i);
                if(ans)
                    ck++;
            }
            cout<<ck<<endl;


        }

    }



    return 0;
}
/*
Ref:LEARNED
*/

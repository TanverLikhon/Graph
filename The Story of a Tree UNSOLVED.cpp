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
#define PI            acos(-1.0)

// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values


//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48

int main()
{
    int q;
    sf(q);
    while(q--)
    {
        int n;
        sf(n);
        for(int i=1; i<n; i++)
        {
            int x,y;
            sff(x,y);
        }
        int g,k;
        sff(g,k);

        mp<int,int>ck;
        for(int i=0; i<g; i++)
        {
            int u,v;
            sff(u,v);
            ck[u]++;
        }

        int arr[sz(ck)];
        int i=0;
        mp<int,int>::iterator it=ck.begin();
        int sum=0;
        while(it!=ck.end())
        {
            arr[i++]=it->ss;
            it++;
        }
        sort(arr,arr+sz(ck));
        i=0;
        int kk=0;
        while(i<sz(ck)&&sum<=k)
        {
            sum+=arr[i++];
            kk++;
        }
        if(sum<k)
            pf("0/1\n");
        else
        {
            if(kk==n)
                pf("1\n");
            else
            {

                int gg=gcd(kk,n);

                pf("%d/%d\n",kk/gg,n/gg);
            }

        }

    }
    return 0;
}
/*
Ref:https://suzyz.github.io/2017/08/29/the-story-of-a-tree/
*/



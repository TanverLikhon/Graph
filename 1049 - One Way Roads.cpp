//http://lightoj.com/volume_showproblem.php?problem=1049
#include<bits/stdc++.h>
using namespace std;
#define sf          scanf
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define l            list
#define pi          pair
#define mp         map
#define nl         printf("\n")
//accepted
int n;
bool LEFT[101];
bool RIGHT[101];
int main()
{
    int t;
    sf("%d",&t);int ck=1;
    while(t--)
    {
        int n;
        sf("%d",&n);
        int    nn=n;
        int l=0,r=0;
        memset(LEFT,false,sizeof(LEFT));
        memset(RIGHT,false,sizeof(RIGHT));
        while(nn--)
        {
            int a,b,c;
            sf("%d%d%d",&a,&b,&c);
            if(RIGHT[a]==false&&LEFT[b]==false)
            {
                RIGHT[a]=true;
                LEFT[b]=true;
                l+=c;
            }
            else
            {
                LEFT[a]=true;
                RIGHT[b]=true;
                r+=c;
            }
        }
        pf("Case %d: %d\n",ck,min(l,r));
        ck++;
    }
    return 0;
}

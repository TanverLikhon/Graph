
#include<bits/stdc++.h>
using namespace std;
#define sf          scanf
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define v           vector
#define l            list
#define p          pair
#define m         map
#define nl         printf("\n")
//
int main()
{
int  w,h,u1,d1,u2,d2;
sf("%d%d%d%d%d%d",&w,&h,&u1,&d1,&u2,&d2);
int snow[101]={0};
snow[d1]=u1;
snow[d2]=u2;
int  W=w;
for(int i=h;i>=0;i--)
{
    W=W+i;
    W=W-snow[i];
    if(W<0)W=0;
}

cout<<W<<endl;
return 0;
}



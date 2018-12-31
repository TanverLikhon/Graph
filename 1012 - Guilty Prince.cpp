//http://lightoj.com/volume_showproblem.php?problem=1012
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
#define white 1
#define gray   2
#define black 3
///accepted 0.012 sec :) first attempt :)
char land[21][21];
int w,h;
int color[21][21];
int ck;
void dfsVisit(int x,int y)
{

    color[x][y]=gray;
    int i=x,j=y;
    if(land[i][j-1]=='.'&&color[i][j-1]==white&&i<h&&(j-1)<w)
    {
        ck++;
        color[i][j-1]=gray;
        dfsVisit(i,j-1);
    }
    if(land[i][j+1]=='.'&&color[i][j+1]==white&&i<h&&(j+1)<w)
    {
        ck++;
        color[i][j+1]=gray;
        dfsVisit(i,j+1);
    }
    if(land[i-1][j]=='.'&&color[i-1][j]==white&&(i-1)<h&&j<w)
    {
        ck++;
        color[i-1][j]=gray;
        dfsVisit(i-1,j);
    }


    if(land[i+1][j]=='.'&&color[i+1][j]==white&&(i+1)<h&&j<w)
    {
        ck++;
        color[i+1][j]=gray;
        dfsVisit(i+1,j);
    }
    color[x][y]=black;

}

int main()
{

    int t;
    sf("%d",&t);
    int c=1;
    while(t--)
    {
        sf("%d%d",&w,&h);
        int x,y;
        for(int i=0; i<h; i++)
        {
            string str;
            cin>>str;
            for(int j=0; j<w; j++)
            {
                land[i][j]=str[j];
                color[i][j]=white;
                if(str[j]=='@')
                {
                    x=i,y=j;
                }
            }

        }
//cout<<x<<"   "<<y<<endl;
        dfsVisit(x,y);
    pf("Case %d: %d\n",c,ck+1);
    c++;
        ck=0;
    }

    return 0;
}


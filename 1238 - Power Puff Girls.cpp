//http://lightoj.com/volume_showproblem.php?problem=1238
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
///accepted :) 0.004 sec  2092kB
int Row,Col;
int a,b,c;
int a1,a2,b1,b2,c1,c2;
char mat[21][21];
struct point
{
    int x;
    int y;
    int dis;
} ;

bool isValid(int row,int col)
{
    return (row>=0&&(row<Row)&&(col>=0)&&(col<Col));
}
int rowNum[4]= {-1,0,0,1};
int colNum[4]= {0,-1,1,0};
void bfs(point src)
{
    bool visited[Row][Col];
    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++)
        visited[i][j]=false;
    queue<point>q;
    //  dis[src.x][src.y]=0;
    point x= src;
    q.push(x);
    while(!q.empty())
    {
        point curr=q.front();

        q.pop();
        if(curr.x==a1&&curr.y==a2)
        {
            a=curr.dis;
        }
        else         if(curr.x==b1&&curr.y==b2)
        {
            b=curr.dis;
        }
        else         if(curr.x==c1&&curr.y==c2)
        {
            c=curr.dis;
        }
        if(a&&b&&c)
            return;
        for(int i=0; i<4; i++)
        {
            int row=curr.x+rowNum[i];
            int col=curr.y+colNum[i];
            if(isValid(row,col)&&mat[row][col]!='#'&&mat[row][col]!='m'&&visited[row][col]==false){
                    visited[row][col]=true;
                point n= {row,col,curr.dis+1};
                // dis[curr.x+rowNum[i]][curr.y+colNum[i]]=dis[curr.x][curr.y]+1;
                q.push(n);
            }
        }
    }
}

int main()
{
    int t,ck=1;
    sf("%d",&t);
    while(t--)
    {
        sf("%d%d",&Row,&Col);
        struct point src;
        for(int i=0; i<Row; i++)
        {
            string str;
            cin>>str;
            for(int j=0; j<Col; j++)
            {
                mat[i][j]=str[j];
                if(mat[i][j]=='h')
                {
                    src.x=i;
                    src.y=j;
                }
                else if(mat[i][j]=='a')
                {
                    a1=i;
                    a2=j;
                }
                else if(mat[i][j]=='b')
                {
                    b1=i;
                    b2=j;
                }
                else if(mat[i][j]=='c')
                {
                    c1=i;
                    c2=j;
                }
            }
        }
        src.dis=0;
        bfs(src);
        pf("Case %d: %d\n",ck,max(a,max(b,c)));
        ck++;
        a=0,b=0,c=0;
    }
    return 0;
}

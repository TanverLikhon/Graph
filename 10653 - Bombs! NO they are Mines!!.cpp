///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1594
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
int Row,Col,r;
bool adj[1000][1000];
struct point
{
    int x;
    int y;
} ;
//accepted 0.138 sec :)
bool isValid(int row,int col)
{
    return (row>=0&&(row<Row)&&(col>=0)&&(col<Col));
}

int rowNum[]= {-1,0,0,1};
int colNum[]= {0,-1,1,0};

int bfs(point src,point dest)
{
bool visited[Row][Col];
int dis[Row][Col];
memset(visited,false,sizeof(visited));
visited[src.x][src.y]=true;
queue<point>q;
dis[src.x][src.y]=0;
point x= src;
q.push(x);

while(!q.empty())
{
    point curr=q.front();

        q.pop();
    if(curr.x==dest.x&&curr.y==dest.y)return dis[curr.x][curr.y];

    for(int i=0;i<4;i++)
    {
        int row=curr.x+rowNum[i];
        int col=curr.y+colNum[i];
        if(isValid(row,col)&&visited[row][col]==false&&adj[row][col])
        {
            visited[row][col]=true;
            point n={row,col};
            dis[row][col]=dis[curr.x][curr.y]+1;
            //queueNode n={{row,col},curr.dist+1};
            q.push(n);
        }
    }
}
}

int main()
{

    while(sf("%d%d",&Row,&Col))
    {
        if(Row==0&& Col==0)
            break;
        memset(adj,true,sizeof(adj));
        sf("%d",&r);
        while(r--)
        {
            int r1,b,b1;
            sf("%d%d",&r1,&b);
            while(b--)
            {
                sf("%d",&b1);
                adj[r1][b1]=false;
            }
        }
        struct   point source;
        struct point  dest;
        sf("%d%d%d%d",&source.x,&source.y,&dest.x,&dest.y);
        int dis=bfs(source,dest);
        pf("%d\n",dis);
    }
    return 0;
}

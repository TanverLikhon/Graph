///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=870
/*Never Give up*/
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
//tle
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int row,col;
int cost[1000][1000];
struct cell
{
    int x, y;
    int distance;
    cell(int x, int y, int distance) :
        x(x), y(y), distance(distance) {}
};
bool operator<(const cell& a, const cell& b)
{
    if (a.distance == b.distance)
    {
        if (a.x != b.x)
            return (a.x < b.x);
        else
            return (a.y < b.y);
    }
    return (a.distance < b.distance);
}
bool isInsideGrid(int i, int j)
{
    return (i >= 0 && i <row && j >= 0 && j < col);
}
int dijkstra()
{
    int dis[row][col];
        for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            dis[i][j]=INT_MAX;
  // memset(dis,INT_MAX,sizeof(dis));
    priority_queue<cell>c;
    c.push(cell(0,0,0));
    dis[0][0]=cost[0][0];
    while(!c.empty())
    {
        cell u=c.top();
        c.pop();
        for(int i=0; i<4; i++)
        {
            int x=u.x+dx[i];
            int y=u.y+dy[i];
            if(isInsideGrid(x,y))
            {
                if(dis[x][y]>dis[u.x][u.y]+cost[x][y])
                {
                    dis[x][y]=dis[u.x][u.y]+cost[x][y];
                    c.push(cell(x,y,dis[x][y]));
                }
            }
        }
    }
    return dis[row-1][col-1];
}
int main()
{
    int t;
    sf("%d",&t);
    while(t--)
    {
        sf("%d%d",&row,&col);
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                sf("%d",&cost[i][j]);
        int x=dijkstra();
        pf("%d\n",x);

    }

    return 0;

    return 0;
}

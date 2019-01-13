/*Never Give up*/
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=870
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
///accepted 1.38 sec :(
int row,col;
int adj[1001][1001];
struct cell
{
    int x,y;
    int distance;
    cell(int x,int y,int distance):x(x),y(y),distance(distance) {}
};
bool operator < (const cell& a,const cell& b)
{
    if(a.distance==b.distance)
    {
        if(a.x!=b.x)
            return (a.x<b.x);
        else
            return (a.y<b.y);
    }
    return (a.distance<b.distance);
}
bool isInsideGrid(int i,int j)
{
    return(i>=0&&i<row&&j>=0&&j<col);
}
int shortest()
{
    int dis[row][col];
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            dis[i][j]=INT_MAX;
    set<cell>st;
    st.insert(cell(0,0,0));
    dis[0][0]=adj[0][0];
    while(!st.empty())
    {
        cell k=*st.begin();
        st.erase(st.begin());
        for(int i=0; i<4; i++)
        {
            int x=k.x+dx[i];
            int y=k.y+dy[i];
            if(isInsideGrid(x,y))
            if(dis[x][y]>(dis[k.x][k.y]+adj[x][y]))
            {
                dis[x][y]=dis[k.x][k.y]+adj[x][y];
                st.insert(cell(x,y,dis[x][y]));
       //     cout<<"Entered "<<endl;
            }
        }
    }

 /*   cout<<"Printing distance "<<endl;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            pf("i  %d  j  %d   dis %d\n",i,j,dis[i][j]);*/
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
                sf("%d",&adj[i][j]);
        int x=shortest();
        pf("%d\n",x);
      //  memset(adj,0,sizeof(adj));
    }

    return 0;
}

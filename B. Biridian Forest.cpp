/*Never Give up*/
/*
Problem  :https://codeforces.com/contest/329/problem/B
Verdict     :AC
Time         :810 ms
Memory  :45300 KB
*/
#include<bits/stdc++.h>
using namespace std;
#define sf(a)          scanf("%d",&a)
#define sff(a,b)         scanf("%d%d",&a,&b)
#define sfff(a,b,c)         scanf("%d%d%d",&a,&b,&c)
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define v           vector
#define l            list
#define pi          pair
#define mp         map
#define nl         printf("\n")
#define en        pf("Entered\n")
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char adj[1005][1005];
bool visited[1005][1005];
int dis[1005][1005];
int r,c;
int ex,ey;
int srcx,srcy;
mp<pi<int,int>,int>mike;
bool isValid(int row,int col)
{
    return (row>=0&&(row<r)&&(col>=0)&&(col<c));
}
struct cell
{
    int x,y;
};
int bfs()
{

    queue<cell>q;
    cell point;
    point.x=ex,point.y=ey;
    visited[ex][ey]=true;
    q.push(point);
    while(!q.empty())
    {
        cell u;
        u=q.front();
        int xx=u.x;
        int yy=u.y;
        q.pop();
        for(int i=0; i<4; i++)
        {
          int   row=xx+dx[i];
           int  col=yy+dy[i];
            if(isValid(row,col)&&visited[row][col]==false&&adj[row][col]!='T')
            {
               // en;
                visited[row][col]=true;
                dis[row][col]=dis[u.x][u.y]+1;
                cell tmp;
                tmp.x=row,tmp.y=col;
            //    u.x=row,u.y=col;
                q.push(tmp);
            }
        }
    }

}
int main()
{
    sff(r,c);
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>adj[i][j];
            if(adj[i][j]=='E')
                ex=i,ey=j;
            else if(adj[i][j]=='S')
                srcx=i,srcy=j;
            else if(adj[i][j]=='0');
            else if(adj[i][j]=='T');
            else
                mike[ {i,j}]=(int)(adj[i][j]-'0');
        }
    }
    bfs();int ck=0;

//cout<<"source "<<dis[srcx][srcy]<<endl;
    mp<pi<int,int>,int>::iterator it;
    for(it=mike.begin();it!=mike.end();it++)
    {

        //cout<<(it->first).first<<"   "<<(it->first).second<<"   "<<it->second<<endl;

 if(dis[(it->first).first][(it->first).second]<=dis[srcx][srcy]&&visited[(it->first).first][(it->first).second])ck+=it->second;
    }
pf("%d\n",ck);
/*

 nl;
    nl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
           // cout<<adj[i][j];
           cout<<dis[i][j];
          // cout<<visited[i][j]<<" ";
        }
        nl;
    }*/
    return 0;
}


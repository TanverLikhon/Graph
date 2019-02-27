/*Never Give up*/
/*
Problem:
Verdict :
Time:
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
char adj[1000][1000];
int n,m;
int srcx,srcy,destx,desty;
bool visited[1000][1000];
int check1[1000][1000];
int r1,c1,r0,c0;
bool isvalid(int row, int col)
{
    return (row >= 0) && (row < n) &&
           (col >= 0) && (col < m);
}
struct cell
{
    int x,y;
    int x0,y0,x1,y1;
};
void bfs(int row,int col)
{
    r1=r0,c1=c0;
    visited[row][col]=true;
    queue<cell>q;
    cell point;
    point.x=row;
    point.y=col;
    point.x0=point.x1=r0;
    point.y0=point.y1=c0;
    q.push(point);
    check1[row][col]=0;
    while(!q.empty())
    {
        cell u;
        u=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            row=u.x+dx[i];
            col=u.y+dy[i];
            if(isvalid(row,col)==true&&adj[row][col]!='*'&&visited[row][col]==false)
            {
                r1=u.x1,c1=u.y1;
                r0=u.x0,c0=u.y0;
                cout<<"---------------------"<<endl;
                cout<<r1<<"   "<<c1<<endl;
                cout<<r0<<"  "<<c0<<endl;
                cout<<"current "<<endl;
                cout<<row<<"  "<<col<<endl;
                cout<<"---------------------"<<endl;

                visited[row][col]=true;

                if(row!=r0&&col!=c0)
                {
                    check1[row][col]=check1[u.x][u.y]+1;
                }
                else
                    check1[row][col]=check1[u.x][u.y];

                cell tmp;
                tmp.x=row,tmp.y=col;
                tmp.x1=row,tmp.y1=col,tmp.x0=r1,tmp.y0=c1;
                q.push(tmp);
            }
        }

    }

}
int main()
{
    sff(n,m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>adj[i][j];
            if(adj[i][j]=='S')
                srcx=i,srcy=j,r0=i,c0=j;
            else if(adj[i][j]=='T')
                destx=i,desty=j;
        }
    }
    check1[srcx][srcy]=0;
    bfs(srcx,srcy);
    /*   for(int i=0; i<n; i++)
       {
           for(int j=0; j<m; j++)
           {
               cout<<check1[i][j]<<" ";
               // cout<<visited[i][j]<<" ";
           }
           nl;
       }
       cout<<check1[destx][desty]<<endl;*/
    if(check1[destx][desty]<=2&&visited[destx][desty])
        pf("YES\n");
    else
        pf("NO\n");
    //cout<<check1[destx][desty]<<endl;
    return 0;
}


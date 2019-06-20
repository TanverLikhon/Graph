///Topological time form LEC
/*tanverlikhon@gmail.com*/
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
int adj[100][100];
int node,edge;
int color[100];
int sTime[100];
int fTime[100];
int Time=1;
stack<int >ans;
void dfsVisit(int x)
{
    color[x]=gray;
    sTime[x]=Time;
    ++Time;
    for(int i=0; i<node; i++)
    {
        if(adj[x][i]==1)
        {
            if(color[i]==white)
            {
                dfsVisit(i);
            }
        }
    }
    color[x]=black;
    fTime[x]=Time;
    ++Time;
ans.push(x);
}
void dfs()
{
    for(int i=0;i<node;i++)
    {
        color[i]=white;
    }
    for(int i=0; i<node; i++)
    {
        if(color[i]==white)
        {
            dfsVisit(i);//cout<<"Entered"<<endl;
        }
    }
}
int main()
{
    sf("%d%d",&node,&edge);
    int n1,n2;
    for(int i=0; i<edge; i++)
    {
        sf("%d%d",&n1,&n2);
        adj[n1][n2]=1;
    }
    dfs();
cout<<"Printing nodes and their discovery and finishing Time"<<endl;
for(int i=0;i<node;i++)
{
    cout<<"NODE "<<i<<"  "<<sTime[i]<<"    "<<fTime[i]<<endl;
}

cout<<"Topological sorting "<<endl;
while(!ans.empty())
{
cout<<ans.top()<<"  ";
ans.pop();
}
    return 0;
}


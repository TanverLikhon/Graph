///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=865
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
#define MAX   2500
///accepted 0.380 sec :)
int edge;
int M,D;
bool adj[MAX][MAX];
void bfs(int startingNode)
{
    queue<int>q;
    bool visited[edge]= {false};
    int day[edge]={0};
    visited[startingNode]=true;
    day[startingNode]=0;
    int ck[edge+1]= {0};
    q.push(startingNode);
    int mday=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<edge; i++)
        {
            //cout<<"i "<<i;
            if(adj[x][i]==true&&visited[i]==false)
            {
                visited[i]=true;
                day[i]=day[x]+1;
                if(day[i]>mday)
                    mday=day[i];
                ck[day[i]]++;
                q.push(i);
            }
        }
    }
    if(mday==0)
        pf("0\n");
    else
    {
        for(int i=0; i<=mday; i++)
        {
            if(ck[i]>M)
            {
                M=ck[i];
                D=i;
            }
        }
    pf("%d %d\n",M,D);
        M=0;
    }



    /*cout<<"\nPrinting levels"<<endl;
    for(int i=0;i<edge;i++)
    {
        cout<<"e "<<i<<" day "<<day[i]<<endl;
    }*/

}
int main()
{
    while(sf("%d",&edge)!=EOF)
    {
        int n1,n2;
        for(int i=0; i<edge; i++)
        {
            sf("%d",&n1);
            while(n1--)
            {
                sf("%d",&n2);
                adj[i][n2]=true;
            }
        }
        int s,t;
        sf("%d",&t);
        while(t--)
        {
            sf("%d",&s);
            bfs(s);
        }
        memset(adj,false,sizeof(adj));
        /*   for(int i=0; i<edge; i++)
           {
               cout<<"E  "<<i<<"->";
               for(int j=0; j<adj[i].size(); j++)
                   cout<<adj[i][j]<<"  ";nl;
           }*/
    }
    return 0;
}


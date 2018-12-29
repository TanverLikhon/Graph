/*6795*/
#include<bits/stdc++.h>
using namespace std;
#define sf          scanf
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define v           vector
#define p          pair
#define m         map
#define nl         printf("\n")

int n,l;
bool adj[200][200];
bool isBipartite()
{
    int color[n];
    for (int i = 0; i < n; ++i)
        color[i] = -1;
    color[0] = 1;
    queue <int> q;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        //cout<<"Size "<<q.size()<<endl;
        for (int v = 0; v < n; ++v)
        {
            if (adj[u][v] ==true&& color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (adj[u][v]==true && color[v] == color[u])
            {

                return false;
            }

        }
    }
    return true;
}
int main()
{

    while(sf("%d",&n))
    {
        if(n==0)
            break;
        sf("%d",&l);
  //bool adj[n][n];
        while(l--)
        {
            int x,y;
            sf("%d%d",&x,&y);
            adj[x][y]=true;
            adj[y][x]=true;
        }
        bool flag=isBipartite();
   //     cout<<"f "<<flag<<endl;
        if(flag==true)
            pf("BICOLORABLE.\n");
        else
            pf("NOT BICOLORABLE.\n");

memset(adj,false,sizeof(adj));
    }

    return 0;
}



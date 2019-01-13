#include<bits/stdc++.h>
using namespace std;
#define sf          scanf
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define v           vector
#define l            list
#define pi          pair
#define mp         map
#define nl         printf("\n")
#define MAX   100
int n,a,b,w,m,e,t,k;
v<pi<int,int>>edge[MAX];
void weightedbfs()
{

    int dis[MAX];
    for(int i=0; i<100; i++)
        dis[i]=INT_MAX;
    dis[0]=0;
    queue<int>q;
    q.push(0);
//cout<<dis[0]<<endl;
for(int i=)
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<edge[x].size(); i++)
        {
            int to=edge[x][i].first;
            w=edge[x][i].second;
if(x==0)
{

}
            if(i>0)
            {
                if(dis[to]>dis[x]+w+60)
                {
                    dis[to]=dis[x]+w+60;

                    q.push(to);
                }
            }
            else
            {
                if(dis[to]>dis[x]+w)
                {
                    dis[to]=dis[x]+w;
                    q.push(to);
                }
            }
        }
        /*    for(int i=0; i<edge[x].size(); i++)
            {
                w=weight[ {x,edge[x][i]}];
                if(dis[edge[x][i]]>w+dis[x])
                {
                    dis[edge[x][i]]=w+dis[x];
                    q.push(edge[x][i]);
                }

            }*/

    }
    cout<<"K  "<<k<<endl;
cout<<" dis   "<<dis[k]<<endl;
}
int main()
{
    string line;
    stringstream ss;
    while(cin>>n)
    {
        sf("%d",&k);
        int speed[n];
        for(int i=0; i<=n; i++)
            sf("%d",&speed[i]);
        getchar();
        int flr[100];
        for(int i=0; i<n; i++)
        {
            getline(cin,line);
            ss.clear();
            ss<<line;
            int x;
            int index=0;
            while(ss>>x)
            {
                flr[index]=x;
                index++;
            }
            for(int j=0; j<index-1; j++)
            {
                int l =j+1;
                edge[flr[j]].pb(make_pair(flr[l],(flr[l]-flr[j])*speed[i]));
                edge[flr[l]].pb(make_pair(flr[j],(flr[l]-flr[j])*speed[i]));
                //  edge[flr[k]].pb(flr[j]);
                // weight[]
            }
        }

        weightedbfs();
                for(int i=0;i<100;i++)edge[i].clear();
    }
    return 0;
}

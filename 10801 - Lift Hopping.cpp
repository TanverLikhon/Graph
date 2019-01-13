/*Never Give up*/
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1742
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
#define mp         map
#define nl         printf("\n")
#define check pf("ENTERED\n)
//accepted 0.00:)
int n,w,k;
v<p<int,int>>edge[100];
struct Node
{
    int cost;
    int node;
    Node() {}
    Node(int n1, int c)
    {
        node = n1;
        cost = c;
    }
    bool operator <(const Node & node)const
    {
        return cost > node.cost;
    }
};

int weightedbfs()
{
    int dis[100];
    for(int i=0; i<100; i++)
        dis[i]=INT_MAX;

    priority_queue<Node>q;
    q.push(Node(0,0));
    dis[0]=0;
    while(!q.empty())
    {
        int parent=q.top().node;
        q.pop();
        //if(parent==k)return dis[k];
        for(int i=0; i<edge[parent].size(); i++)
        {
            int next= edge[parent][i].first;
            w= edge[parent][i].second;
            if(dis[next]>dis[parent]+w+60)
            {
                dis[next]=dis[parent]+w+60;
                q.push(Node(next,dis[next]));
            }
        }


    }
    //  cout<<"distances "<<endl;
    //  for(int i=0;i<100;i++)
    //    cout<<i<<"->"<<dis[i]<<endl;
    //cout<<dis[k]<<endl;
    return dis[k];
}
int main()
{
    string line;
    stringstream ss;
    while(cin>>n)
    {
        sf("%d",&k);
        int speed[n];
        for(int i=0; i<n; i++)
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
            for(int l=0; l<index; l++)
                for(int m=l+1; m<index; m++)
                {
                    edge[flr[l]].pb(make_pair(flr[m],(flr[m]-flr[l])*speed[i]));
                    edge[flr[m]].pb(make_pair(flr[l],(flr[m]-flr[l])*speed[i]));
                }

        }
        int x;
        x= weightedbfs();
        if(x==INT_MAX)
            pf("IMPOSSIBLE\n");
        else if(x==0)
            pf("0\n");
        else
            pf("%d\n",x-60);
        for(int i=0; i<100; i++)
            edge[i].clear();
    }
    return 0;
}


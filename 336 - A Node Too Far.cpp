/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=272&mosmsg=Submission+received+with+ID+22532135*/
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
#define white 0
#define gray 2
#define black 3
//accepted 0.11 sec ;)
map<int,vector<int>>node;
map<int,int>dis;
int visitednodes=1;
int total;
int bfs(int startingNode,int ttl)
{
    int ck=0;
    queue<int>q;


    if(node[startingNode].size()==0)
    {

        visitednodes=total;
        return total;
    }
    q.push(startingNode);
    dis[startingNode]=0;
    while(!q.empty())
    {
        int x;
        x=q.front();
        q.pop();
        int s=node[x].size();
        for(int i=0; i<s; i++)
        {
            if(dis[node[x][i]]==0&&node[x][i]!=startingNode)
            {
                visitednodes++;
                dis[node[x][i]]=dis[x]+1;
                if(dis[node[x][i]]>ttl)
                    ck++;
                q.push(node[x][i]);
            }
        }
    }
   /*   m<int,int>::iterator it;
    for(it=dis.begin();it!=dis.end();it++)
          cout<<it->first<<"    "<<it->second<<endl;*/
    return ck;
}
int main()
{
    int n,ck=1;
    while(sf("%d",&n)&&n!=0)
    {
        int n1,n2;
        while(n--)
        {

            sf("%d%d",&n1,&n2);
            node[n1].pb(n2);
            node[n2].pb(n1);
        }
        int x,y;
        total=node.size();
        while( sf("%d%d",&x,&y))
        {
            if(x==0&&y==0)
                break;
            int m=  bfs(x,y);
            dis.clear();
            //    cout<<node.size()<<endl;
          //  cout<<"M   "<<m<<"Total "<<node.size()<<"Visit "<<visitednodes<<endl;
            m=m+(total-visitednodes);
            pf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",ck,m,x,y);
            // cout<<"M  "<<m<<endl;
            ck++;
            visitednodes=1;
        }
        node.clear();
    }

    return 0;
}



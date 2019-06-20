/*Never Give up*/

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
#define MAX   100001
using namespace std;
vector <int> adj[MAX];
bool visited[MAX];
int fTime[MAX];
int dTime[MAX];
int nodes, edges;
int Time=1;
stack<int >st;
void dfs(int s)
{
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
        }
    }
st.push(s);
}
void initialize()
{
    for(int i=0; i<nodes; i++)
        visited[i]=false;
}
int main()
{
        sff(nodes,edges);

        for(int i = 0; i < edges; ++i)
        {
            int x,y;
            sff(x,y);
            adj[x].push_back(y);
        }
        initialize();
        for(int i = 1; i <=nodes; ++i)
        {
            if(visited[i] == false)
            {
                dfs(i);
            }
        }
       cout<<"Printing discovering and finishing time "<<endl;
       for(int i=0;i<=nodes;i++)
        cout<<"Node  "<<i<<" :: "<<dTime[i]<<" -> "<<fTime[i]<<endl;
        cout<<"Topological sort :  ";
        while(!st.empty())
        {
            int x=st.top();
            cout<<x<<endl;
            st.pop();
        }
    return 0;
}

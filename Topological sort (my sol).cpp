/*Never Give up*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
vector <int> adj[MAX];
bool visited[MAX];
int nodes, edges, x, y, ck = 0;
stack<int>st;
void dfs(int s)
{
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); ++i)
    {

        if(visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
            ck++;
        }
    }
    st.push(s);
}

void initialize()
{
    for(int i=1; i<=nodes; i++)visited[i]=false;
}

int main()
{

    cin>>nodes>>edges;
    for(int i = 0; i < edges; ++i)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }

    initialize();

    for(int i = 1; i <= nodes; ++i)
    {
        if(visited[i] == false)
        {
            dfs(i);

        }
    }
    cout<<"after topological sort"<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}

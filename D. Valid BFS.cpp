/*Never Give up*/
///https://codeforces.com/contest/1037/problem/D
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
#define MAX 200002
//187 ms	9300 KB accepted
//learned new thing
v<int>edge[MAX];
int N,M;
int arr[MAX];
int arr1[MAX];
void bfs()
{

    bool visited[N+1]= {0};
    visited[1]=true;
    queue<int >q;
    q.push(1);
    int k=1;
    bool flag=false;
    while(!q.empty())
    {
        int x=q.front();
        //cout<<x<<" ";
        if(arr1[k]!=x)
        {
            pf("No\n");
            return ;
        }
        k++;
        q.pop();
        for(int i=0; i<edge[x].size(); i++)
        {
            int u=edge[x][i];
            if(visited[u]==false)
            {
                visited[u]=true;
                q.push(u);
            }
        }
    }
    //  en;
    pf("Yes\n");
    return;
}
bool comp(int a,int b )
{
    return arr[a]<arr[b];
}
int main()
{

    sf(N);
    M=N-1;
    while(M--)
    {
        int x,y;
        sff(x,y);
        edge[x].pb(y);
        edge[y].pb(x);
    }
 int x;
    for(int i=1; i<=N; i++)
    {

        sf(x);
        arr[x]=i;
        arr1[i]=x;
    }
for(int i=1;i<=N;i++)
{
   sort(edge[i].begin(),edge[i].end(),comp);
}
bfs();

    return 0;
}

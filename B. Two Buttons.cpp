/*Never Give up*/
//https://codeforces.com/problemset/problem/520/B
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
#define MAX 10001
//accepted 30 ms 0kB
int dis[MAX];
int bfs(int src,int dest)
{

    bool visited[MAX]= {false};
    dis[dest]=0;
    visited[dest]=true;
    queue<int>q;
    q.push(dest);
    while(!q.empty())
    {
        int x=q.front();
        if(x==src)return dis[x];
        q.pop();
       if(x%2)
       {
           if(visited[x+1]==false)
           {
               visited[x+1]=true;
               dis[x+1]=dis[x]+1;
               q.push(x+1);
           }
       }
       else
       {
           if(visited[x+1]==false)
           {
               visited[x+1]=true;
               dis[x+1]=dis[x]+1;
               q.push(x+1);

           }
           if(visited[x/2]==false)
           {
               visited[x/2]=true;
               dis[x/2]=dis[x]+1;
               q.push(x/2);
           }
       }


    }

}

int main()
{
    int n,m;
    sff(n,m);
    pf("%d\n",bfs(n,m));
    return 0;
}

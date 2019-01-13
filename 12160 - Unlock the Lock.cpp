//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3312
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
//accepted at 0.00 sec :)
int d;
int L,U,r;
bool bfs(int L,int U,int R[])
{
    bool flag=false;
    queue<int >q;
    q.push(L);
    bool visited[10000]= {false};
    int dis[10000]= {0};
    visited[L]=true;
    dis[L]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x==U)
        {
        //    cout<<"Entered"<<endl;
            d=dis[x];
            flag=true;
            break;
        }
        for(int i=0; i<r; i++)
        {
            int m1=(x%10000+R[i]%10000)%10000;
            if(visited[m1]==false)
            {
                visited[m1]=true;
                dis[m1]=dis[x]+1;
                q.push(m1);
            }
        }
    }
return flag;
}
int main()
{

int ck=1;
    while(sf("%d%d%d",&L,&U,&r))
    {
        if(L==0&&U==0&&r==0)
            break;
        int R[r];
        for(int i=0; i<r; i++)
            sf("%d",&R[i]);
        bool flag=bfs(L,U,R);
        pf("Case %d: ",ck);
        if(flag==true)
            pf("%d\n",d);
        else
            pf("Permanently Locked\n");
            ck++;
    }

    return 0;
}



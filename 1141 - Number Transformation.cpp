//http://lightoj.com/volume_showproblem.php?problem=1141
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
#define MAX   1001
#define en        pf("ENTERED\n")
//accepted 40ms :)
int d;
int L,U,r;
v<int>primes;
v<int>R;
void factors(int x)
{
    int i=0;
    while(x>primes[i])
    {
        if(x%primes[i]==0)
        {
            R.pb(primes[i]);
        }
        i++;
    }
}
bool bfs(int L,int U)
{
    bool flag=false;
    queue<int >q;
    q.push(L);
    bool visited[10001]= {false};
    int dis[10001]= {0};
    visited[L]=true;
    dis[L]=0;
    if(L>U)
        return false;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x==U)
        {

            d=dis[x];
            flag=true;
            break;
        }

        factors(x);
        for(int i=0; i<R.size(); i++)
        {
            int m1=x+R[i];
//cout<<"m1 "<<m1<<endl;
            if(visited[m1]==false)
            {
                visited[m1]=true;
                dis[m1]=dis[x]+1;
             if(m1<=U)
                q.push(m1);
            }
        }
        R.clear();
    }
    return flag;
}
void sieve()
{
    bool isPrime[MAX+1];
 memset(isPrime,true,sizeof(isPrime));
    for(int i=2; i*i<=MAX; i++)
        if(isPrime[i]==true)
            for(int j=i*i; j<=MAX; j=j+i)
                isPrime[j]=false;
    for(int i=2; i<=MAX; i++)
        if(isPrime[i])
            primes.pb(i);
  //en;
}

int main()
{
    sieve();
    int ck=1;
    int t;
    sf("%d",&t);
    while(t--)
    {
        int x,y;
        sf("%d%d",&x,&y);
        bool flag=bfs(x,y);

        pf("Case %d: ",ck);
        if(flag==true)
            pf("%d\n",d);
        else
            pf("-1\n");
        ck++;
    }

    return 0;
}



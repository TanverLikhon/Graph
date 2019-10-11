/*Never Give up*/
/*
Problem  :
Verdict     :
Time         :
Memory  :
*/
#include<bits/stdc++.h>
using namespace std;
#define sf(a)          scanf("%d",&a)
#define sff(a,b)         scanf("%d%d",&a,&b)
#define sfff(a,b,c)         scanf("%d%d%d",&a,&b,&c)
#define sffff(a,b,c,d)         scanf("%d%d%d%d",&a,&b,&c,&d)
#define sl(a)          scanf("%lld",&a)
#define sll(a,b)         scanf("%lld%lld",&a,&b)
#define slll(a,b,c)         scanf("%lld%lld%lld",&a,&b,&c)
#define sllll(a,b,c,d)         scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define sc(a) scanf("%c",&a)
#define sz(a)              a.size()
#define ff first
#define ss second
#define all(a)          a.begin(), a.end()
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pf         printf
#define pf1(a)        pf("%d\n",a);
#define PI  acos(-1)
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define vi           vector<int>
#define vl           vector<ll>
#define li            list<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define mp         map
#define nl         printf("\n")
#define en        pf("Entered\n")
#define en1      pf("Entered 2\n")
#define gcd(a,b) __gcd(a,b)

// priority_queue<int, vector<int>, greater<int> > Q;//for smaller values

#define MAX    51

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/


//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
int adj[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int srcx,srcy,destx,desty,dirr;
int n,m;
bool isvalid(int x,int y)
{
    if(x<0||x>=n-1||y<0||y>=m-1)return false;
    return true;

}
struct cell
{
    int a,b,direction,distance;

};

bool operator <(cell a,cell b)
{

    return a.distance>b.distance;

}

int bfs()
{
    if(isvalid(srcx,srcy)==false||isvalid(destx,desty)==false)return -1;
    if(adj[srcx][srcy]>0||adj[destx][desty]>0)return -1;
    cell tmp;
    tmp.a=srcx,tmp.b=srcy,tmp.direction=dirr,tmp.distance=0;

    dist[srcx][srcy]=0;

    priority_queue<cell>q;
    q.push(tmp);
    while(!q.empty())
    {
        cell u;
        u=q.top();
        q.pop();
        int x,y,dis,dir;
        x=u.a;
        y=u.b;
        dis=u.distance;
        dir=u.direction;
        if(x==destx&&y==desty)return dist[destx][desty];
        if(dir==0)///north//up
        {
            for(int i=1; i<=3; i++)//down
            {
                int tmpx=x+i,tmpy=y;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+3)
                    {
                        dist[tmpx][tmpy]=dis+3;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=2,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//up
            {
                int tmpx=x-i,tmpy=y;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+1)
                    {
                        dist[tmpx][tmpy]=dis+1;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=0,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//left
            {
                int tmpx=x,tmpy=y-i;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+2)
                    {
                        dist[tmpx][tmpy]=dis+2;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=1,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//right
            {
                int tmpx=x,tmpy=y+i;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+2)
                    {
                        dist[tmpx][tmpy]=dis+2;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=3,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

        }


        else if(dir==1)///west//left
        {
            for(int i=1; i<=3; i++)//down
            {
                int tmpx=x+i,tmpy=y;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+2)
                    {
                        dist[tmpx][tmpy]=dis+2;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=2,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//up
            {
                int tmpx=x-i,tmpy=y;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+2)
                    {
                        dist[tmpx][tmpy]=dis+2;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=0,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//left
            {
                int tmpx=x,tmpy=y-i;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+1)
                    {
                        dist[tmpx][tmpy]=dis+1;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=1,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//right
            {
                int tmpx=x,tmpy=y+i;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+3)
                    {
                        dist[tmpx][tmpy]=dis+3;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=3,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }
        }



        else if(dir==2)///south//down
        {
            for(int i=1; i<=3; i++)//down
            {
                int tmpx=x+i,tmpy=y;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+1)
                    {
                        dist[tmpx][tmpy]=dis+1;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=2,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//up
            {
                int tmpx=x-i,tmpy=y;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+3)
                    {
                        dist[tmpx][tmpy]=dis+3;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=0,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//left
            {
                int tmpx=x,tmpy=y-i;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+2)
                    {
                        dist[tmpx][tmpy]=dis+2;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=1,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//right
            {
                int tmpx=x,tmpy=y+i;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+2)
                    {
                        dist[tmpx][tmpy]=dis+2;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=3,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

        }


        else if(dir==3)///east//right
        {
            for(int i=1; i<=3; i++)//down
            {
                int tmpx=x+i,tmpy=y;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+2)
                    {
                        dist[tmpx][tmpy]=dis+2;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=2,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//up
            {
                int tmpx=x-i,tmpy=y;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+2)
                    {
                        dist[tmpx][tmpy]=dis+2;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=0,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//left
            {
                int tmpx=x,tmpy=y-i;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+3)
                    {
                        dist[tmpx][tmpy]=dis+3;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=1,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

            for(int i=1; i<=3; i++)//right
            {
                int tmpx=x,tmpy=y+i;
                if(isvalid(tmpx,tmpy))
                {
                    if(adj[tmpx][tmpy]>0)break;
                    if(dist[tmpx][tmpy]>dis+1)
                    {
                        dist[tmpx][tmpy]=dis+1;
                        cell temp;
                        temp.a=tmpx,temp.b=tmpy,temp.direction=3,temp.distance=dist[tmpx][tmpy];
                        q.push(temp);
                    }
                }
            }

        }

    }
    return -1;


}
int main()
{

    while(sff(n,m))
    {
        if(n==0&&m==0)return 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                visited[i][j]=0;
                dist[i][j]=INT_MAX;
                sf(adj[i][j]);
                if(adj[i][j])
                {
                    if(i==0&&j>0)adj[i][j-1]=2;
                    else if(j==0&&i>0)adj[i-1][j]=2;
                    else adj[i][j-1]=2,adj[i-1][j]=2,adj[i-1][j-1]=2;
                }
                if(i==n-1||j==m-1)adj[i][j]=2;
            }
        sff(srcx,srcy);
        sff(destx,desty);
        srcx--,srcy--,destx--,desty--;
        // adj[srcx][srcy]=-8,adj[destx][desty]=-99;
        string str;
        cin>>str;
        if(str=="south")dirr=2;
        else if(str=="north")dirr=0;
        else if(str=="west")dirr=1;
        else dirr=3;
        pf1(bfs());


        /*cout<<"printing MAT "<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<adj[i][j]<<" ";

            }
            nl;

        }


        cout<<"printing distance "<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
              if(dist[i][j]!=INT_MAX)
                cout<<dist[i][j]<<" ";
                else cout<<0<<" ";

            }
            nl;

        }*/


    }
    return 0;
}
/*
Ref:


9 10
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
7 3 2 7 south

*/

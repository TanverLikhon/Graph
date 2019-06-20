/*Never Give up*/
/*
Problem  :https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3104&mosmsg=Submission+received+with+ID+23227967
AC
Time         :0.010s
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
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pf         printf
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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char arr[102][102];
int row,col;
void dfs(int x,int y)
{
    if(x<0||x>=row||y<0||y>=col||arr[x][y]=='.')
        return ;
    char ch=arr[x][y];
    arr[x][y]='.';
    for(int i=0; i<4; i++)
        dfs(x+dx[i],y+dy[i]);
}
int main()
{
    int t;
    sf(t);
int c=1;
    while(t--)
    {      int ck=0;
       int n;
        sf(n);
        row=n,col=n;
        cin.ignore();
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                cin>>arr[i][j];

        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                if(arr[i][j]=='x')
                {
                    ck++;
                    dfs(i,j);
                }
            }
         pf("Case %d: %d\n",c++,ck);
    }

    return 0;
}



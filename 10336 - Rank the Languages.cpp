/*Never Give up*/
/*
Problem  :https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1277&mosmsg=Submission+received+with+ID+23226095
Verdict     :AC
Time         :0.000s
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
char arr[1002][1002];
int row,col;
void dfs(int x,int y,char src)
{
    if(x<0||x>=row||y<0||y>=col||arr[x][y]=='*'||arr[x][y]!=src)
        return ;
    char ch=arr[x][y];
    arr[x][y]='*';
    for(int i=0; i<4; i++)
        dfs(x+dx[i],y+dy[i],ch);
}
struct cell
{
    char ch;
    int cn=0;
};
bool cmp(cell a,cell b)
{
    if(a.cn==b.cn)return a.ch<b.ch;
    return a.cn>b.cn;
}
int main()
{
    int t;
    int ck[27];
    sf(t);
int c=1;
    while(t--)
    {
        cell cnk [26];
        sff(row,col);
        cin.ignore();
        for(int i=0; i<27; i++)
            ck[i]=0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                cin>>arr[i][j];

        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                char s=arr[i][j];
                if(arr[i][j]!='*')
                {
                    ck[(int)s-97]++;
                    dfs(i,j,s);
                }
            }
            int cc=0;
        for(int i=0; i<26; i++)
        {
            if(ck[i]!=0)
            {
                cnk[cc].ch=char(i+97);
                cnk[cc].cn=ck[i];cc++;
            }
        }
        sort(cnk,cnk+cc,cmp);
         //   cout<<char(i+97)<<"  "<<ck[i]<<endl;
            pf("World #%d\n",c++);
            for(int i=0;i<cc;i++)
                pf("%c: %d\n",cnk[i].ch,cnk[i].cn);
         //       cout<<cnk[i].ch<<"  "<<cnk[i].cn<<endl;
    }

    return 0;
}



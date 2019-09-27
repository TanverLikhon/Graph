/*Never Give up*/
/*
Problem  :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2931
Verdict     :AC
Time         :0.030
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

#define MAX    105

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
char adj[MAX][MAX];
int n,m,ins,ck;
string str;
///1=n 2=e 3=s 4=w

bool isValid(int x,int y)
{
    // cout<<"cc "<<adj[x][y]<<endl;
    if(x>=0&&x<n&&y>=0&&y<m&&adj[x][y]!='#')return true;
    return false;

}


void dfs(int srcx,int srcy,char dir,int idx)
{

 // cout<<" char  "<<adj[srcx][srcy]<<"  dir "<<dir<<"  idx "<<str[idx]<<" "<<endl;;
  //  cout<<" x  y  "<<srcx<<" - "<<srcy<<endl;
  if(adj[srcx][srcy]=='*'){
      ck++;adj[srcx][srcy]='.';
 // cout<<"STAR"<<endl;
     }
    int x,y;
    if(idx==sz(str))return;

   // else if(adj[srcx][srcy]=='#')en,dfs(srcx,srcy,dir,idx+1);
     if(str[idx]=='D')
    {
   // cout<<"enteed dd"<<endl;
             //cout<<" char  "<<adj[srcx][srcy]<<"  dir "<<dir<<"  idx "<<str[idx]<<endl;;


        if(dir=='N')dfs(srcx,srcy,'L',idx+1);
        else if(dir=='O')dfs(srcx,srcy,'N',idx+1);
        else if(dir=='S')dfs(srcx,srcy,'O',idx+1);
        else if(dir=='L')dfs(srcx,srcy,'S',idx+1);
    }
    else if(str[idx]=='E')
    {
  //  en;
        if(dir=='N')dfs(srcx,srcy,'O',idx+1);
        else if(dir=='O')dfs(srcx,srcy,'S',idx+1);
        else if(dir=='S')dfs(srcx,srcy,'L',idx+1);
        else if(dir=='L')dfs(srcx,srcy,'N',idx+1);


    }
    else if(str[idx]=='F')
    {
     // en;


        if(dir=='N')
        {
            x=srcx-1,y=srcy;//cout<<isValid(x,y)<<endl;
            if(isValid(x,y));
                else x++;

       //         cout<<x<<" --"<<y<<endl;
               // cout<<"cc "<<adj[x][y]<<
            dfs(x,y,'N',idx+1);


        }
        else if(dir=='L')
        {
            x=srcx,y=srcy+1;
            if(isValid(x,y));
                else y--;

          //                      cout<<x<<" --"<<y<<endl;

            dfs(x,y,'L',idx+1);

        }
        else if(dir=='S')
        {
            x=srcx+1,y=srcy;
            if(isValid(x,y));
                else x--;

          //                      cout<<x<<" --"<<y<<endl;

            dfs(x,y,'S',idx+1);

        }
        else if(dir=='O')
        {
            x=srcx,y=srcy-1;
            if(isValid(x,y));
                else y++;

         //                       cout<<x<<" --"<<y<<endl;

            dfs(x,y,'O',idx+1);

        }
      //  en;
    }

}

int main()
{
    int srcx,srcy;
    char dir;
    while(sfff(n,m,ins)&&n&&m&&ins)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                cin>>adj[i][j];
                if(adj[i][j]=='N'||adj[i][j]=='S'||adj[i][j]=='L'||adj[i][j]=='O')
                    srcx=i,srcy=j,dir=adj[i][j],adj[i][j]='.';

            }
        cin>>str;
        dfs(srcx,srcy,dir,0);

pf1(ck);ck=0;





        /*  cout<<"printing"<<endl;
                  for(int i=0; i<n; i++)
                  {
                      for(int j=0; j<m; j++)
                      {
                          cout<<adj[i][j]<<" ";
                      }
                      nl;
                  }
        */
    }



    return 0;
}
/*
Ref:
3 3 2
***
*N*
***
DE
4 4 5
...#
*#O.
*.*.
*.#.
FFEFF
10 10 20
....*.....
.......*..
.....*....
..*.#.....
...#N.*..*
...*......
..........
..........
..........
..........
FDFFFFFFEEFFFFFFEFDF





*/

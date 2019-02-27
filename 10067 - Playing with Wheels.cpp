/*Never Give up*/
/*
Problem:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1008
Verdict :AC
Time:0.050 Rank: 152 :)
*/
#include<bits/stdc++.h>
using namespace std;
#define sf(a)          scanf("%d",&a)
#define sff(a,b)         scanf("%d%d",&a,&b)
#define sfff(a,b,c)         scanf("%d%d%d",&a,&b,&c)
#define sffff(a,b,c,d)         scanf("%d%d%d%d",&a,&b,&c,&d)
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
#define MAX  100002
int s1,s2,s3,s4;
int dd1,dd2,dd3,dd4;
int ck[10][10][10][10];
int dest;
struct cell
{
    int a,b,c,d;
};
int ps(int x)
{
    if(x<0)
        return 9;
    else if(x>9)
        return 0;

    return x;
}

int bfs()
{
    //en;
    int dis[10][10][10][10];
    bool visited [10][10][10][10];// cout<< visited[s1][s2][s3][s4]<<endl;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<10; k++)
            {
                for(int l=0; l<10; l++)
                {
                    visited[i][j][k][l]=false;
                    dis[i][j][k][l]=-1;

                }
            }
        }
    }
    cell u;
    u.a=s1,u.b=s2,u.c=s3,u.d=s4;
    dis[s1][s2][s3][s4]=0;
    visited[s1][s2][s3][s4]=true;
    queue<cell>q;
    q.push(u);
    while(!q.empty())
    {
        cell x=q.front();
        q.pop();
        cell tmp;
        int aa,bb,cc,dd;
        aa=x.a,bb=x.b,cc=x.c,dd=x.d;
        //if(aa==dd1&&bb==dd2&&cc==dd3&&dd==dd4)
        int a1=ps(aa+1),a2=ps(aa-1),b1=ps(bb+1),b2=ps(bb-1);
        int c1=ps(cc+1),c2=ps(cc-1),d1=ps(dd+1),d2=ps(dd-1);
        if(visited[aa][bb][cc][d1]==false)
        {
            visited[aa][bb][cc][d1]=true;
            dis[aa][bb][cc][d1]= dis[aa][bb][cc][dd]+1;
            tmp.a=aa;
            tmp.b=bb;
            tmp.c=cc;
            tmp.d=d1;
            //    if(makenumber(aa,bb,cc,d1)<=dest)

            //  if(ck[makenumber(aa,bb,cc,d1)]!=1)
            if(ck[aa][bb][cc][d1]!=1)
                q.push(tmp);
        }

        if(visited[aa][bb][cc][d2]==false)
        {
            visited[aa][bb][cc][d2]=true;
            dis[aa][bb][cc][d2]= dis[aa][bb][cc][dd]+1;
            tmp.a=aa;
            tmp.b=bb;
            tmp.c=cc;
            tmp.d=d2;
            if(ck[aa][bb][cc][d2]!=1)
                q.push(tmp);
        }


        if(visited[aa][bb][c1][dd]==false)
        {
            visited[aa][bb][c1][dd]=true;
            dis[aa][bb][c1][dd]= dis[aa][bb][cc][dd]+1;
            tmp.a=aa;
            tmp.b=bb;
            tmp.c=c1;
            tmp.d=dd;
            //              if(makenumber(aa,bb,c1,dd)<=dest)

            if(ck[aa][bb][c1][dd]!=1)
                q.push(tmp);
        }

        if(visited[aa][bb][c2][dd]==false)
        {
            visited[aa][bb][c2][dd]=true;
            dis[aa][bb][c2][dd]= dis[aa][bb][cc][dd]+1;
            tmp.a=aa;
            tmp.b=bb;
            tmp.c=c2;
            tmp.d=dd;
            //                 if(makenumber(aa,bb,c2,dd)<=dest)

            if(ck[aa][bb][c2][dd]!=1)
                q.push(tmp);
        }



        if(visited[aa][b1][cc][dd]==false)
        {
            visited[aa][b1][cc][dd]=true;
            dis[aa][b1][cc][dd]= dis[aa][bb][cc][dd]+1;
            tmp.a=aa;
            tmp.b=b1;
            tmp.c=cc;
            tmp.d=dd;
            //             if(makenumber(aa,b1,cc,dd)<=dest)

            if(ck[aa][b1][cc][dd]!=1)
                q.push(tmp);
        }

        if(visited[aa][b2][cc][dd]==false)
        {
            visited[aa][b2][cc][dd]=true;
            dis[aa][b2][cc][dd]= dis[aa][bb][cc][dd]+1;
            tmp.a=aa;
            tmp.b=b2;
            tmp.c=cc;
            tmp.d=dd;

            if(ck[aa][b2][cc][dd]!=1)
                q.push(tmp);
        }



        if(visited[a1][bb][cc][dd]==false)
        {
            visited[a1][bb][cc][dd]=true;
            dis[a1][bb][cc][dd]= dis[aa][bb][cc][dd]+1;
            tmp.a=a1;
            tmp.b=bb;
            tmp.c=cc;
            tmp.d=dd;
            if(ck[a1][bb][cc][dd]!=1)
                q.push(tmp);
        }

        if(visited[a2][bb][cc][dd]==false)
        {
            visited[a2][bb][cc][dd]=true;
            dis[a2][bb][cc][dd]= dis[aa][bb][cc][dd]+1;
            tmp.a=a2;
            tmp.b=bb;
            tmp.c=cc;
            tmp.d=dd;
            if(ck[a2][bb][cc][dd]!=1)
                q.push(tmp);
        }

    }
    return dis[dd1][dd2][dd3][dd4];
}

int main()
{
    int t,f;
    sf(t);
    while(t--)
    {
        sffff(s1,s2,s3,s4);
        sffff(dd1,dd2,dd3,dd4);
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                for(int k=0; k<10; k++)
                {
                    for(int l=0; l<10; l++)
                    {
                        ck[i][j][k][l]=0;
                    }
                }
            }
        }
        sf(f);
        while(f--)
        {
            int x,y,z,zx;
            sffff( x,y,z,zx);
            ck[x][y][z][zx]=1;
        }
        pf("%d\n",bfs());

    }
    return 0;
}

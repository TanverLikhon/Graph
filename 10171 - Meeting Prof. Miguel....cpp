/*Never Give up*/
/*
Problem  :https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1112
Verdict     :AC
Time         :0sec
Memory  :Rank 874 :)
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
#define pf1        pf("%d\n");
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

#define MAX    29

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
vi edgesY[MAX];
vi edgesM[MAX];
int mn=INT_MAX,mx=INT_MIN;
mp<pi,int>weightY;
mp<pi,int>weightM;
int src,dest;
int distY[MAX];
int distM[MAX];
void weightedbfs()
{
    /*  for(int i=mn; i<=mx; i++)
      {
          cout<<i<<"--->";
          for(int j=0; j<sz(edgesY[i]); j++)
              cout<<edgesY[i][j]<<" ";
          nl;
      }

      for(int i=mn; i<=mx; i++)
      {
          cout<<i<<"--->";
          for(int j=0; j<sz(edgesM[i]); j++)
              cout<<edgesM[i][j]<<" ";
          nl;
      }*/
    int visitedY[mx+1];
    int visitedM[mx+1];
    for(int i=mn; i<=mx; i++)
    {
        visitedM[i]=false;
        visitedY[i]=false;
        distY[i]=INT_MAX;
        distM[i]=INT_MAX;
    }


    // cout<<" "<<src <<endl;
    queue<int>q;
    q.push(src);
    distY[src]=0;
    distM[dest]=0;
    while(!q.empty())
    {
        int x=q.front(),w;
        // cout<<"hh"<<x<<endl;
        q.pop();
        // cout<<sz(edgesY[x])<<endl;
        for(int i=0; i<edgesY[x].size(); i++)
        {
            //    cout<<i<<endl;
            w=weightY[ {x,edgesY[x][i]}];
            if(distY[edgesY[x][i]]>w+distY[x])
            {
                distY[edgesY[x][i]]=w+distY[x];
                q.push(edgesY[x][i]);
            }
        }
    }



    queue<int>q1;
    q1.push(dest);
    while(!q1.empty())
    {
        int x=q1.front(),w;
        //cout<<x<<" -<<";
        q1.pop();
        //  cout<<"sz "<<edgesM[x].size()<<endl;
        for(int i=0; i<edgesM[x].size(); i++)
        {
            // en;
            //   cout<<edgesM[x][i]<<"   ";
            w=weightM[ {x,edgesM[x][i]}];
            if(distM[x]+w<distM[edgesM[x][i]])
            {
                distM[edgesM[x][i]]= distM[x]+w;
                q1.push(edgesM[x][i]);
            }
        }
    }

    ll mnn=INT_MAX;
    // int idx;
    /* cout<<mx<<"  "<<mn<<endl;
     cout<<"MMM"<<endl;
     for(int i=mn;i<=mx;i++)
     {
         if(distM[i]!=INT_MAX)
         cout<<char(i+65)<<" ->  "<<distM[i]<<endl;
     }


     cout<<"YYY"<<endl;
     for(int i=mn;i<=mx;i++)
     {
         if(distY[i]!=INT_MAX)
         cout<<char(i+65)<<" ->  "<<distY[i]<<endl;
     }
    */
  vi idx;//cout<<"monjur "<<char(src+65)<<"   prof"<<char(dest+65)<<endl;
    for(int i=mn; i<=mx; i++)
        if(distM[i]+distY[i]<mnn&&distM[i]!=INT_MAX&&distY[i]!=INT_MAX)
        {
         //   cout<<char(i+65)<<"----->"<<distM[i]<<"  "<<distY[i]<<"  "<<mnn<<endl;
         idx.clear();
            mnn=distM[i]+distY[i],idx.pb(i+65);
        }
          else if(distM[i]+distY[i]==mnn&&distM[i]!=INT_MAX&&distY[i]!=INT_MAX)
        {
         //   cout<<char(i+65)<<"----->"<<distM[i]<<"  "<<distY[i]<<"  "<<mnn<<endl;
       //  idx.clear();
            mnn=distM[i]+distY[i],idx.pb(i+65);
        }
      //      mnn=distM[i]+distY[i],idx.pb(i+65),en;
//    mnn=min(mnn,distM[i]+distY[i]);
    sort(all(idx));
    if(mnn!=INT_MAX)
    {
        pf("%lld",mnn);
        for(int i=0; i<sz(idx); i++)
            pf(" %c",idx[i]);
        nl;
    }
    else
        pf("You will never meet.\n");
}

int main()
{
    int e;
    while(sf(e))
    {
        if(e==0)
            break;
        for(int i=0; i<e; i++)
        {

            //en;
            char ch1,ch2,ch3,ch4;
            int x;
            cin>>ch1>>ch2>>ch3>>ch4;
            sf(x);

            int c3=int(ch3)-65,c4=int(ch4)-65;
            mn=min(mn,min(c3,c4));
            mx=max(mx,max(c3,c4));
            if(ch1=='Y')
            {
                edgesY[c3].pb(c4);
                weightY[ {c3,c4}]=x;
                if(ch2=='U')
                {
                }
                else
                {
                    edgesY[c4].pb(c3);
                    weightY[ {c4,c3}]=x;
                }
            }
            else
            {
                edgesM[c3].pb(c4);
                weightM[ {c3,c4}]=x;
                if(ch2=='U')
                {
                }
                else
                {
                    edgesM[c4].pb(c3);
                    weightM[ {c4,c3}]=x;
                }
            }
        }
        char chh,chhh;
        cin>>chh>>chhh;
        src=int(chh)-65,dest=int(chhh)-65;
        //cout<<mn<<" "<<mx<<endl;
        weightedbfs();
        for(int i=mn; i<=mx; i++)
        {
            edgesM[i].clear();
            edgesY[i].clear();

        }
        weightM.clear(),weightY.clear();
    }



    return 0;
}

/*
penalty at
14
Y B S J 389
M B B O 472
Y B Z H 455
M B N L 250
M U S J 415
Y U R X 497
Y B W P 450
M B J T 262
Y B V G 328
Y B I S 22
Y B C O 167
Y B U W 62
Y U I C 478
M B C Y 1
J S
Ref:
*/


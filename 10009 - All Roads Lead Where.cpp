//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=950&mosmsg=Submission+received+with+ID+22745408
/*Never Give up*/
#include<bits/stdc++.h>
using namespace std;
#define sf          scanf
#define pf         printf
#define ll           long long
#define ull        unsigned long long
#define pb        push_back
#define v           vector
#define l            list
#define pi          pair
#define m         map
#define nl         printf("\n")
#define en        pf("Entered\n")
//accepted 0.00 sec rank 947
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
m<char,v<char>>mp;
char ch1;
m<char,char>parent;
void print(char ch)
{
    //cout<<ch<<endl;
//cout<<parent[ch]<<endl;
    if(ch==ch1)
    {
        pf("%c",ch);
        return;
    }
    print(parent[ch]);
    pf("%c",ch);
}
void bfs(string start,string dest)
{
    bool visited[91];
    for(int i=65; i<91; i++)
    {
        visited[i]=false;
    }
    queue<char>q;
    q.push(start[0]);
    while(!q.empty())
    {
        char ch=q.front();
        q.pop();
        if(ch==dest[0])
        {
            print(ch);
            nl;
            return;
        }
        for(int i=0; i<mp[ch].size(); i++)
        {
            if(visited[(int)mp[ch][i]]==false)
            {
                visited[(int)mp[ch][i]]=true;
                parent[mp[ch][i]]=ch;
                q.push(mp[ch][i]);
            }
        }

    }
}
int main()
{
    int t;
    string str1,str2;
    sf("%d",&t);
    while(t--)
    {
        int r,t1;
        sf("%d%d",&r,&t1);
        while(r--)
        {
            cin>>str1>>str2;
            mp[str1[0]].pb(str2[0]);
            mp[str2[0]].pb(str1[0]);
        }
        while(t1--)
        {
            cin>>str1>>str2;
            ch1=str1[0];
            bfs(str1,str2);
            parent.clear();
        }
        if(t)
        nl;
        mp.clear();
    }

    return 0;
}

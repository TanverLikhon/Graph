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
#define f_input  freopen("input.txt","r",stdin);
#define f_output freopen("output.txt","w",stdout);
#define sz 206
///accepted but my previous solution's fault is not cleared
m<int,int>fib;
void generatefib()
{
    int i, n, t1 = 1, t2 = 2, nextTerm;
    for (i = 1; i <= 100; ++i)
    {
        fib[t1]=i-1;
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}
char str[sz],str2[sz];
int res[sz];
char output[sz];
int main()
{
    generatefib();
    int t,n,s,ck;
    sf("%d",&t);
    getchar();
    while(t--)
    {


        for(int i=0; i<101; i++)
            output[i]=' ';
        output[101]='\0';
        ck=0;
        sf("%d",&n);
        getchar();

        s=n;

        while(n--)
        {
            int x;
            sf("%d",&x);
            getchar();
            res[ck]=x;
            ck++;
        }
        scanf("%[^\n]%*c", str);
        int k=0;
        for (int i = 0; str[i]; i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                str2[k++]=str[i];
            }
        }
        str2[k]='\0';
        int ind=0,x=0;
        for(int i=0; i<s; i++)
        {
            if(fib[res[i]]>=0)
            {
                output[fib[res[i]]]=str2[x];
                ind=max(ind,fib[res[i]]);
                x++;
            }
        }

        ind++;
        output[ind]='\0';
        pf("%s",output);
       nl;
    }
    return 0;
}

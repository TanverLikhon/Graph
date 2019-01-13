/*Never Give up*/
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1819
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
int bin[10]={0,128,64,32,16,8,0,4,2,1};
//accepted 0.00 sec:)
int main()
{
    int num=0;
    string str,str1;
    getline(cin,str1);
    getline(cin,str);
     while(str[0]=='|')
     {
         int num=0;
for(int i=1;i<=9;i++)
    if(str[i]=='o')num+=bin[i];
         pf("%c",num);
         getline(cin,str);
     }

return 0;
}

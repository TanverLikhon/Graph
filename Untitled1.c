#include<stdio.h>

int main()
{
int a,b,x;
scanf("%d%d",&a,&b);
add(a,b);
    return 0;
}
 void add(int a,int b)
{
    int sum;
    sum=a+b;
    printf("%d",sum);
}

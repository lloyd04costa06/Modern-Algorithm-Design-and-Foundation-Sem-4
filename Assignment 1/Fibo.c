#include<stdio.h>
int count=0;
int main()
{
    int a=0,b=1,i,n,c;

     printf("ENTER THE VALUE OF N: ");
    scanf("%d",&n);

   
    switch(n)
    {
        case 1:
         count++; //count for case 1
        printf("0");
        break;

        case 2:
         count++; //count for case 2
        printf("1");
        break;

        default:
         count++; // count for default case
        printf("0 1");

    }

    for(i=2;i<n;i++)
    {
         count++; //count for the for loop
        c=a+b; count++; //ount for the assignment
        printf(" %d",c); count++; //print count
        a=b; count++; //assignment count
        b=c; count++; //assignment count
    }
     count++; //last test case count of the loop

}
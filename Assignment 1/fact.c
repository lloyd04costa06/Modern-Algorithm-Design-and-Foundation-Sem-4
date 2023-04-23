#include<stdio.h>
int count=0;
int main()
{
    int i,fact=1,n;
    printf("ENTER THE VALUE OF N: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        count++; //counter for the loop
        fact=fact*i;count++; //counter for the assignment
    }
    count++;//counter for the last test case

    printf("FACTORIAL OF %d is %d\n",n,fact);
    printf("STEP COUNT= %d\n",count);
}

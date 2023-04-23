#include<stdio.h>
int count=0;
int main()
{
    int flag=0,i,n;
     printf("ENTER THE VALUE OF N: ");
    scanf("%d",&n);

	count++; //for the if condition
    if(n==0||n==1)
    {
        count++;//for the assignment
         flag=1;
    }
   
    for(i=2;i<n;i++)
    {
        count++;/// for the loop
        if(n%i==0)
        {
            count++;// for the if conditon
            flag=1; count++;//for the assignment
            break;
        }
    }
 
    count++;// for the last test case of the loop
    count++;//for the if condition
    if(flag==0)
    printf("IT IS A PRIME NUMBER\n");
    else
     printf("IT IS NOT A PRIME NUMBER\n");

     printf("\nSTEP COUNT= %d\n",count);


}
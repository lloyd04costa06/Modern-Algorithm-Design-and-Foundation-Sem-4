#include<stdio.h>
#define MAX 10
int count=0;

int main()
{
    int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];
    int c,d,k,N,sum=0;
    printf("ENTER VALUE OF N: ");
    scanf("%d",&N);
	printf("FOR MATRIX A ");
    printf("ENTER ELEMENTS INTO YOUR MATRIX\n");
    
    for(c=0;c<N;c++)
    {
        count++;//for the loop
    	  for(d=0;d<N;d++)
          {
              count++;//for the loop
              scanf("%d",&A[c][d]); count++;//for the loop

          }
  		  
    }
    printf("FOR MATRIX B ");
    printf("ENTER ELEMENTS INTO YOUR MATRIX\n");
    for(c=0;c<N;c++)
    {
        count++;//for the loop
    	  for(d=0;d<N;d++)
          {
              count++;//for the loop
              scanf("%d",&B[c][d]); count++;//for the loop
          }	  
    }
       
     for ( c = 0 ; c < N ; c++ )
     {
          count++;//for the loop
        for ( d = 0 ; d < N ; d++ )
        {
             count++;//for the loop
        	  for ( k = 0 ; k < N ; k++ )
            {
                 count++;//for the loop
          	  sum = sum + A[c][k]*B[k][d]; count++;//for the assignment
            }
    
            C[c][d] = sum; count++;//for the assignment
            sum = 0; count++;//for the assignment
        }
          
      }
   printf("\nAFTER MULTIPLYING A AND B\n");
     for(c=0;c<N;c++)
     {
          count++;//for the loop
        for(d=0;d<N;d++)
        {
            printf("%d ",C[c][d]);count++;//for the printf
         
        }
        printf("\n");count++;//for the printf
         
     }
    printf("\nSTEP COUNT: %d\n",count);

  
}
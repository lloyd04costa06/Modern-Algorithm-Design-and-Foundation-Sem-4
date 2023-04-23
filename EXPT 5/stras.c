#include<stdio.h>

#define A11 a[0][0]
#define A12 a[0][1]
#define A21 a[1][0]
#define A22 a[1][1]
#define B11 b[0][0]
#define B12 b[0][1]
#define B21 b[1][0]
#define B22 b[1][1]

#define P ((A11+A22)*(B11+B22))
#define Q (B11*(A21+A22))
#define R (A11*(B12-B22))
#define S (A22*(B21-B11))
#define T (B22*(A11+A12))
#define U ((B11+B12)*(A21-A11))
#define V ((B21+B22)*(A12-A22))

#define CN count++
int count=0;

int main()
{
	int a[2][2],b[2][2],c[2][2],i,j;
	
	printf("ENTER ELEMENTS INTO YOUR FIRST 2x2 MATRIX:\n");
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
	scanf("%d",&a[i][j]);	
	
	printf("ENTER ELEMENTS INTO YOUR SECOND 2x2 MATRIX:\n");
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
	scanf("%d",&b[i][j]);
	
	count+=7;
	c[0][0]=P+S-T+V;CN;
	c[0][1]=R+T;CN;
	c[1][0]=Q+S;CN;
	c[1][1]=P+R-Q+U;CN;
	
	printf("RESULT:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		printf("%d ",c[i][j]);
		printf("\n");
	}
	printf("\nSTEP COUNT= %d\n",count);

}

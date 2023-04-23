#include<stdio.h>
int V,GRAPH[10][10];
#define MAX 10
#define NEXTLINE printf("\n")
#define G(m) m<0||m>=V

void Line_Generator(int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("-");
}

void print_G()
{
  int i,j;
  printf("    |   ");
   for(i=0;i<V;i++)
  	  printf("%-3d  ",i);
  	  NEXTLINE;Line_Generator((V*5)+5);NEXTLINE;  /*NO. OF - BETWEEN 2 ROWS IS 5 DASHES AND INTIALLY 5 PREDEFINED DASHES*/
  for(i=0;i<V;i++)
  {
  	 printf("%-2d  |   ",i);
  	 
      for(j=0;j<V;j++)
      printf("%-3d  ",GRAPH[i][j]);
      printf("\n");
  }
}

int main()
{
	V=3;
	int i,j;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		GRAPH[i][j]=0;
	}
	
	print_G();
	
}
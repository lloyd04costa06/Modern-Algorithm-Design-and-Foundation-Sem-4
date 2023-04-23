#include<stdio.h>
#define MAX 10
#define INFINITY 999
#define NEXTLINE printf("\n")
#define CNT count++
#define Print_Infinity printf("oo  ")
int GRAPH[MAX][MAX],A[MAX][MAX];
int V,E;
int count=0;
void G_create()
{
 int i,j;
 printf("ENTER NUMBER OF VERTICES:\n");
 scanf("%d",&V);

 printf("ENTER ADJACENCY MATRIX:\n");

 for(i=0;i<V;i++)
 for(j=0;j<V;j++)
 {
 scanf("%d",&GRAPH[i][j]);
 if(i!=j&&GRAPH[i][j]==0)
 GRAPH[i][j]=INFINITY;
if(i==j)
 GRAPH[i][j]=0;
 }

}
void Reset()
{
int i,j;
for(i=0;i<V;i++)
{
for(j=0;j<V;j++)
{
if(GRAPH[i][j]==0&&i!=j)
GRAPH[i][j]=INFINITY;
if(i==j)
GRAPH[i][j]=0;
}
}
}
int min(int a, int b)
{
if(a<b)
return a;
else
return b;
}
void Line_Generator(int n)
{
int i;
for(i=0;i<n;i++)
printf("-");
}
void print_G(int x)
{
 int i,j;
NEXTLINE;NEXTLINE;
 printf(" A%d | ",x);
 for(i=0;i<V;i++)
 printf("%-3d ",i);
 NEXTLINE;Line_Generator((V*5)+5);NEXTLINE; /*NO. OF -
BETWEEN 2 ROWS IS 5 DASHES AND INTIALLY 5 PREDEFINED DASHES*/
 for(i=0;i<V;i++)
 {
 printf("%-2d | ",i);

 for(j=0;j<V;j++)
 {
 if(A[i][j]==INFINITY)
 Print_Infinity;
 else
printf("%-3d ",A[i][j]);
 }

 printf("\n");
 }
}
void All_Pair_Shortest()
{
int i,j,k;
for(i=0;i<V;i++)
{
CNT;
for(j=0;j<V;j++)
{CNT;A[i][j]=GRAPH[i][j];CNT;}
}
print_G(0);
for(k=0;k<V;k++)
{
CNT;
for(i=0;i<V;i++)
{
CNT;
for(j=0;j<V;j++)
{CNT;A[i][j]=min(A[i][j],A[i][k]+A[k][j]);CNT;}
}
print_G(k+1);
}
}

int main()
{
G_create();
Reset();
All_Pair_Shortest();
printf("\nSTEP COUNT: %d\n",count);
}

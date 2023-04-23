#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define CNT count++
int count=0;
int p[MAX],n,v,c=0;
struct EDGE
{
  int src;
  int dest;
  int w;
}E[MAX],FINAL[MAX];

int comparator(const void *a,const void *b)
{
  struct EDGE *a1=(struct EDGE *)a;
  struct EDGE *b1=(struct EDGE *)b;
  if(a1->w<b1->w)return -1;
  if(a1->w>b1->w)return 1;
}

void edge_input()
{
  int  i;
  printf("\n\nENTER NUMBER OF VERTICES: ");
  scanf("%d",&v);
  printf("ENTER YOUR EDGES (FORMAT: Source,Destination,Weight)\n");
  printf("ENTER -1,-1,-1 TO EXIT\n");
  for(i=0;i<v*v-1;i++)
  {
    printf("[%d]: ",i);
    scanf("%d,%d,%d",&E[i].src,&E[i].dest,&E[i].w);
    if(E[i].src==-1&&E[i].dest==-1&&E[i].w==-1)
    break;
  }
  n=i;
}

void Union(int i,int j)
{ p[i]=j;CNT; }

int Find(int i)
{
  while(p[i]>=0)
  {CNT; i=p[i];CNT;}

  return i;
}

int KruskalMST()
{
  int i,j,k;
  qsort(E,n,sizeof(struct EDGE),comparator);
  for(i=0;i<n;i++)
  {CNT; p[i]=-1;CNT; }

  i=0;CNT; 
  int minCost=0;CNT; 
  while(i<=v-1)
  { 
  	CNT; 
    j=Find(E[i].src);CNT; 
    k=Find(E[i].dest);CNT; 
    if(j!=k)
    {
    	CNT; 
      FINAL[c++]=E[i];CNT; CNT; 
      minCost+=E[i].w;CNT; 
      Union(j,k);
    }
    i++;CNT; 
  }
  return(minCost);
  
}

void printEdge(struct EDGE *x,int n1)
{
  printf("\n\n^^^^^^^^^KRUSKAL'S MST^^^^^^^^^^^\n");
  printf("*********************************\n");
  printf("SOURCE     DESTINATION     WEIGHT\n");
  printf("*********************************\n");
  int i;
  for(i=0;i<n1;i++)
  {
    printf("%-15d",x[i].src);
    printf("%-14d",x[i].dest);
    printf("%-10d\n",x[i].w);
  }
  printf("*********************************\n");

}

int main()
{
 edge_input();
 KruskalMST();
 printEdge(FINAL, v-1);
   printf("                       MINCOST=%d\n",KruskalMST());
 printf("\nSTEP COUNT= %d\n",count);
}

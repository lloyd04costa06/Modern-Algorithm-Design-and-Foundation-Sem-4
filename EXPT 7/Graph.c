#include<stdio.h>
#define MAX 10
#define G(m) m<0||m>=V
int GRAPH[MAX][MAX];
int V,E;

void reset_G()
{
  int i,j;
  for(i=0;i<V;i++)
  {
    for(j=0;j<V;j++)
    GRAPH[i][j]=0;
  }
}

void print_G()
{
  int i,j;
  for(i=0;i<V;i++)
  {
      for(j=0;j<V;j++)
      printf("%d ",GRAPH[i][j]);
      printf("\n");
  }
}

void G_create()
{
  int i,x,y,w;
  printf("ENTER NUMBER OF VERTICES:\n");
  scanf("%d",&V);
    reset_G();
  E=V*(V-1);

    printf("\n\nENTER EDGES(X,Y) AND IT WEIGHT (W) FOR YOUR GRAPH (FORMAT X,Y,W) (TO EXIT -1,-1,-1)\n");
    do{
      printf("-->");
      scanf("%d,%d,%d",&x,&y,&w);
      if(G(x)||G(y))
      {printf("INVALID EDGE\n");}
      else
      {GRAPH[x][y]=w;}
    }while(x!=-1&&y!=-1);
}
int main()
{

  int choice;
  while(1)
  {
    printf("1: CREATE A GRAPH\n");
    printf("2: ENTER NEW EDGES\n");
    printf("3: DELETE AN EDGE\n");
    printf("4: DISPLAY GRAPH\n");
    printf("\nENTER YOU CHOICE: ");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
      G_create();
      break;

      case 2:
      break;

      case 3:
      break;

      case 4:
        print_G();
      break;
    }

  }




}

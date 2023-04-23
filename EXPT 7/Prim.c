#include<stdio.h>
#include<limits.h>
#define MAX 10
#define G(m) m<0||m>=V
#define CNT c++
int c=0;
int GRAPH[MAX][MAX];
int V,E, minCost=0,count=0;
enum STATUS{VISITED,UNVISITED};

struct MSTEDGE
{
  int src;
  int dest;
  int w;
}MST[MAX];

void printMST(struct MSTEDGE *x,int n1)
{
  printf("\n\n^^^^^^^^^^PRIM'S'S MST^^^^^^^^^^^\n");
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
  printf("                       MINCOST=%d",minCost);
}


void primMST()
{
  int i,j;
  int cost[MAX][MAX];
  int dist[MAX],from[MAX];
  enum STATUS node[MAX];

 //***********INITIAL CONDITIONS*****************

  for(i=0;i<V;i++)
  for(j=0;j<V;j++)
  {
  	CNT;CNT;
    if(GRAPH[i][j]==0)
    { CNT;cost[i][j]=INT_MAX;CNT;}
    else
    { CNT;cost[i][j]=GRAPH[i][j];CNT;}

  }

  dist[0]=0;CNT;
  node[0]=VISITED;CNT;


  for(i=1;i<V;i++)
  {
  	CNT;
    dist[i]=cost[0][i];CNT;
    from[i]=0;CNT;
    node[i]=UNVISITED;CNT;
  }

  int u; //minimum edge to destination edge
  int v; //from which source vertex
  int x;
//***********************************************

  for(x=0;x<V-1;x++)
  {
     CNT;int min_distance_edge=INT_MAX;CNT;

    for(i=1;i<V;i++) //Searches the smallest edge of a particular vertex 
    {
    	CNT;
      if(node[i]==UNVISITED && dist[i]<min_distance_edge )
      {
         CNT;min_distance_edge=dist[i];CNT;
         v=i;CNT;
      }
 
    }
     u=from[v];CNT; //It stores the source vertex info
    MST[count].src=v;CNT;
    MST[count].dest=u;CNT;
    MST[count].w=cost[v][u];CNT;

     count++;CNT;
     node[v]=VISITED;CNT;

     for(i=1;i<V;i++) //Distance array is updated
     {
     	CNT;
       if(node[i]==UNVISITED && cost[i][v]<dist[i])
       {
   		  CNT;
         dist[i]=cost[i][v];CNT;
         from[i]=v;CNT;
       }
     }
     minCost+=cost[u][v];CNT;
  }
}

void reset_G()
{
  int i,j;
  for(i=0;i<V;i++)
  {
    for(j=0;j<V;j++)
    GRAPH[i][j]=0;
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
      if(x==-1&&y==-1&&w==-1)
      {break;}
      else if(G(x)||G(y))
    {printf("INVALID EDGE\n");}
      else
      {GRAPH[x][y]=w;GRAPH[y][x]=w;}
    }while(x!=-1&&y!=-1);
}

int main()
{
    G_create();
    primMST();
    printMST(MST,count);
    printf("\nSTEP COUNT= %d\n",c);
}
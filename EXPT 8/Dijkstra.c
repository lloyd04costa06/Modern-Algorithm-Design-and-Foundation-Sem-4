#include<stdio.h>
#include<limits.h>
#define MAX 10
#define INFINITY 9999
#define CNT count++
int GRAPH[MAX][MAX];
int V,E;
enum STATUS{TRUE,FALSE};
int count =0;


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


void dijkstras()
{
    enum STATUS S[MAX];
    int i,j,src,index,w,dist[MAX];

    printf("ENTER SOURCE VERTEX: ");
    scanf("%d",&src);
	printf("\n\nSINGLE SOURCE SHORTEST PATH (VERTEX: DISTANCE)\n");
    for(i=0;i<V;i++)
    {
        CNT; dist[i]=GRAPH[src][i];CNT;
        S[i]=FALSE;CNT;
    }
    dist[src]=0;CNT;
    S[src]=TRUE;CNT;

    for(i=0;i<V-1;i++)
    {
        CNT;int min=INFINITY;CNT;
        for(j=0;j<V;j++)
        {
        	CNT;
            if(dist[j]<=min && S[j]==FALSE)
            {
               CNT; min=dist[j];CNT;
                index=j;CNT;
            }
        }

        S[index]=TRUE;CNT;

        for(w=0;w<V;w++)
        {
        	CNT;
            if(S[w]==FALSE && dist[w]>(dist[index]+GRAPH[index][w]) && dist[index]!=INFINITY && GRAPH[index][j]!=INFINITY)
            {CNT;dist[w]=dist[index]+GRAPH[index][w];CNT;}
        } 

    }
    for(i=0;i<V;i++)
    {
        if(dist[i]==INFINITY)
        printf("%d: NO PATH!\n",i);
        else
        printf("COST(%d,%d)=%d\n",src,i,dist[i]);
    }
    	 
}

int main()
{   
    G_create();
    dijkstras();
    printf("STEP COUNT: %d\n",count);

}

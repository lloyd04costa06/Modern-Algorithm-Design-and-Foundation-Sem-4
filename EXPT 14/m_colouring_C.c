#include<stdio.h>
#define MAX 10

#define NEXTLINE printf("\n")
#define CNT count++

int GRAPH[MAX][MAX],Colors[MAX];
int V,E,M;
int count=0;


void G_create()
{
    int i,j;
    printf("ENTER NUMBER OF VERTICES:\n");
    scanf("%d",&V);

       printf("ENTER NUMBER OF COLOURS:\n");
    scanf("%d",&M);

    printf("ENTER ADJACENCY MATRIX:\n");

    for(i=0;i<V;i++)
    for(j=0;j<V;j++)
    {
        scanf("%d",&GRAPH[i][j]);
    }

    for(i=0;i<V;i++)//set the color array to 0
    Colors[i]=0;
}

void   print_Coloured_Graph()
{
    int i;
    for(i=0;i<V;i++)
    {
        printf("%d ",Colors[i]);
    }
    NEXTLINE;
}

void NextValue(int k)
{
    while(1)
    {
         Colors[k]=(Colors[k]+1)%(M+1); //Generate a color

         if(Colors[k]==0) //if generated color is 0 then just return
         return;

         int j;
         for(j=0;j<V;j++) //Now check if color is not clashing with the adjacent nodes
         {
            if(GRAPH[k][j]!=0 && Colors[j]==Colors[k])
                 break;
         }

         if(j==V)//it means if all nodes are checked and nothng is clashing then return
         return;
    }
  
}
//K is basically the node number
void m_coloring(int k)
{
    while(1)
    {
        NextValue(k); //To find the color for K

        if(Colors[k]==0) //If no color assigned then return, Meaning you cant assign color to it
        return;
        
        if(k==V-1) //If all the vertices of the graph are colored then just print assignment color array
        print_Coloured_Graph();
        else
        m_coloring(k+1); //else move to next node
    }
}

int main()
{
    G_create();
    printf("\n\n****** |COLOURED GRAPH| ******\n");
    m_coloring(0);
}

/*
 
 k=0   k=1   
 @-----@
 |     |
 |     |
 |     |
 @-----@
 k=3   k=2

 
*/
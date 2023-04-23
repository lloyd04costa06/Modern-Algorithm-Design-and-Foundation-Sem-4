#include<iostream>
#include<windows.h>
using namespace std; 
#define MAX 10

#define NEXTLINE cout<<"\n"
#define CNT count++

int GRAPH[MAX][MAX],Colors[MAX];
int V,E,M;
int count=0;

enum ColourScheme{BLUE=1,GREEN,CYAN,RED,PURPLE,YELLOW,};

void Line_Generator(int n)
{
	int i;
	for(i=0;i<n;i++)
	cout<<"-";
}

void G_create()
{
    int i,j;
    cout<<"ENTER NUMBER OF VERTICES:\n";
    cin>>V;

       cout<<"ENTER NUMBER OF COLOURS:\n";
    cin>>M;

    cout<<"ENTER ADJACENCY MATRIX:\n";

    for(i=0;i<V;i++)
    for(j=0;j<V;j++)
    {
        cin>>GRAPH[i][j];
    }

    for(i=0;i<V;i++)
    Colors[i]=0;
}

void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

void  print_Coloured_Graph()
{
    int i;
    for(i=0;i<V;i++)
    {
        if(Colors[i]==1)
        SetColor(RED);

         if(Colors[i]==2)
           SetColor(BLUE);

         if(Colors[i]==3)
           SetColor(GREEN);

         if(Colors[i]==4)
           SetColor(YELLOW);

         if(Colors[i]==5)
           SetColor(CYAN);

         if(Colors[i]==6)
           SetColor(PURPLE);

        cout<<Colors[i]<<"     ";
    }
    NEXTLINE;
}

void NextValue(int k)
{
    while(1)
    {
         Colors[k]=(Colors[k]+1)%(M+1);CNT;
         if(Colors[k]==0)
         {CNT;return;}
         int j;
         for(j=0;j<V;j++)
         {
            if(GRAPH[k][j]!=0 && Colors[j]==Colors[k])
                 {CNT;break;}
         }
         if(j==V)
        {CNT;return;}
    }
  
}
void m_coloring(int k)
{
    while(1)
    {
        CNT;NextValue(k);CNT;
        if(Colors[k]==0)
        {CNT;return;}
        
        if(k==V-1)
        {CNT;print_Coloured_Graph();}
        else
        { m_coloring(k+1);CNT;}
    }
}

int main()
{
    G_create();
    cout<<"\n\n****** |COLOURED GRAPH| ******\n";
    cout<<"-------------------------------\n";
    cout<<"Red|Blue|Green|Yellow|Cyan|Purple\n";
    cout<<" 1 |  2 |  3  |   4  |  5 |  6   \n\n";
   
    for(int i=0;i<V;i++)
    {cout<<"["<<i+1<<"]"<<"   ";}
    cout<<endl;
    Line_Generator((V*6)+3);
    cout<<endl;

    m_coloring(0);
    cout<<"STEP COUNT: "<<count<<endl;
}
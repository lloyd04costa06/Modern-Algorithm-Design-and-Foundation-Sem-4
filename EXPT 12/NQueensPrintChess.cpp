#include<iostream>
#include<math.h>
#include<iomanip>
#define MAX 10
#define CNT cntt++
using namespace std;

int outcome[MAX],n,count=0,cntt=0;
int TupleDATABASE[1000][MAX],dataBcnt=1;

void printChessboard()
{
    int x;
    cout<<"ENTER INDEX NUMBER OF THE TUPLE TO BE PRINTED: ";
    cin>>x;cout<<endl;
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(TupleDATABASE[x][i]==j)
            cout<<"Q"<<" ";
            else
            cout<<"^"<<" ";
        }
        cout<<endl;
    }
}

void Print_Outcome()
{
 
    cout<<setw(4)<<++count<<"| "<<"{";
    int i,j;
    for(i=1;i<=n;i++,j++)
    {
        TupleDATABASE[dataBcnt][i]=outcome[i];

        cout<<outcome[i];
        if(i!=n)
        cout<<",";
    }
    cout<<"}      ";

    dataBcnt++;
    if(count%2==0)
    cout<<endl;
}
bool Place(int k,int i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        CNT;
        if(outcome[j]==i || abs(outcome[j]-i)==abs(j-k))
        {CNT;return false;}
    }
    return true;
}

void NQueens(int k,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        CNT;
        if(Place(k,i))
        {
            CNT;
            outcome[k]=i;CNT;
            if(k==n)
            {CNT;Print_Outcome();}
            else
            {CNT;NQueens(k+1,n);}
        }
    }
}

void setPrint()
{
    int i;
    cout<<"  {";
    for(i=1;i<=n;i++)
    {
        cout<<"X"<<i;
        if(i!=n)
        cout<<",";
    }
    cout<<"} "<<endl;
}

int main()
{
    int choice;
    cout<<"ENTER VALUE OF N: ";
    cin>>n;
    cout<<endl<<"      POSSIBLE SOLUTIONS";
    setPrint();cout<<endl;
    NQueens(1,n);
      cout<<"STEP COUNT: "<<cntt<<endl;
    

    while(1)
    {
       cout<<"\n\n________________________OPTIONS___________________________\n";
       cout<<"PRESS 1: TO PRINT CHESSBOARD REPRESENTATION OF ANY TUPLE\n";
       cout<<"PRESS 2: TO EXIT\n";
       cout<<"ENTER YOUR CHOICE: ";
       cin>>choice;
       
        switch(choice)
        {
            case 1:printChessboard();break;
            case 2: return 0;
        }
    
    }

   
}

#include<iostream>
#include<windows.h>
#include<algorithm>
#include<string>
#define CNT cntt++
#define RED 4
#define WHITE 7
using namespace std;
int m,n,f[200],cntt=0;


void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

void HighlightPattern(int i,string text,string pattern)
{
     cout<<"\n\nPATTERN MATCHED!"<<endl;
    //substr() used to slice the string for colouring
    cout<<text.substr(0,i);
    SetColor(RED);
    cout<<text.substr(i,m);
    SetColor(WHITE);
    cout<<text.substr(i+m,n);

    cout<<endl<<"FROM: "<<i+1<<" TO "<<i+m;
}

void KMPFailureFunction(string pattern)
{
    int i=1,j=0;
    f[0]=0;CNT;
    while(i<m)
    {
        CNT;
        if(pattern[j]==pattern[i])
        {
            CNT;
            f[i]=j+1;CNT;
            i++;CNT;
            j++;CNT;
        }
        else if(j>0)
        {
            j=f[j-1];CNT;
        }
        else
        {
            f[i]=0;CNT;
            i++;CNT;
        }
    }

}

int KMPmatch(string text, string pattern)
{
    KMPFailureFunction(pattern);
    int i=0,j=0;CNT;
    while(i<n)
    {
        CNT;
        if(pattern[j]==text[i])
        {
            if(j == m-1)
            {
               CNT; return i-m+1;
            }
            i++;j++;CNT;CNT;
        }
        else if(j>0)
        {
            j=f[j-1];CNT;
        }
        else
        {
            i++;CNT;
        }
    }
    cout<<"NO SUBSTRING PRERSENT!"; CNT;
      cout<<"\nSTEP COUNT: "<<cntt;
    exit(0);  

}

int main()
{
    string text,pattern;int i;
  
    cout<<"ENTER A STRING: ";
    getline(cin,text);
    n=text.length();

    cout<<"ENTER PATTERN STRING: ";
    getline(cin,pattern);
    m=pattern.length();

    HighlightPattern(KMPmatch(text,pattern),text,pattern);
      cout<<"\nSTEP COUNT: "<<cntt;
}
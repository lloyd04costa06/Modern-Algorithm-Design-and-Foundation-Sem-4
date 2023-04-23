#include<iostream>
#include<windows.h>
#define RED 4
#define WHITE 7
#define CNT cntt++
using namespace std;
int m,n,cntt=0;

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

int BruteForce_patternMatching(string text, string pattern)
{
    int j;
    for(int i=0;i<=n-m;i++)
    {
        CNT;
        j=0;   CNT;
        while(j<m && text[i+j]==pattern[j])
        {
              CNT; j++;  CNT;
        }
        if(j==m)
        {   CNT;return i;}
    }
    
    cout<<"NO SUBSTRING PRERSENT!";   CNT;
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

    HighlightPattern(BruteForce_patternMatching(text,pattern),text,pattern);
    cout<<"\nSTEP COUNT: "<<cntt;
}
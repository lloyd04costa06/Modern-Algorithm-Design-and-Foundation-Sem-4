#include<iostream>
#include<windows.h>
#include<algorithm>
#include<string>
#define CNT cntt++
#define RED 4
#define WHITE 7
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

int last(string pattern,char c)
{
    int L=pattern.find_last_of(c);
    if(L!=string::npos)
    return L;
    else
    return -1;
}

int BMmatch(string text, string pattern)
{
    int i=m-1;CNT;
    int j=m-1;CNT;

    do{
        CNT;
        if(pattern[j]==text[i])
        {
            CNT;
            if(j==0)
            {CNT;return i;}
            else
            {
                i--;CNT;
                j--;CNT;
            }
        }
        else
        {
            i=i+m-min(j,1+last(pattern,text[i]));CNT;
            j=m-1;CNT;
        }
    }while(i<=n-1);

    cout<<"NO SUBSTRING PRERSENT!"; 
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

    HighlightPattern(BMmatch(text,pattern),text,pattern);
     cout<<"\nSTEP COUNT: "<<cntt;
}
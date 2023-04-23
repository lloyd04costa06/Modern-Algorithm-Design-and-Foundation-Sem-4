#include<iostream>
#include<algorithm>
#include<string>
#define CNT cntt++
using namespace std;
int m,n,cntt=0;

int last(string pattern,char c)
{
    int L=pattern.find_last_of(c); //inbuilt function to find last occurence of a character
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
            {
                CNT;
                return i;
            }
            else
            {
                i--;CNT;
                j--;CNT;
            }
        }
        else
        {
            i=i+m-min( j,1+last(pattern,text[i]) );CNT;
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
    

    int k=BMmatch(text,pattern);
    cout<<"Pattern Matched from "<<k<<"to"<<k+(m-1);   

    /*TEXT:
       | L | L | O | Y | D | C | O | S | T | A |
         0   1   2   3   4   5   6   7   8   9
        
        TEXT.length()=10
        n=10

     PATTERN
       | O | Y | D |
         0   1   2

         PATTERN.length()=3
         so m=3

     so the pattern is matched at location 2 to 4
     so we know that BM fucntion will return 2
     so we just add (m-1) to 2 and we get 4

     if we added just m then it wld be
     2+3=5 which wld inccorect.


    */
   
     cout<<"\nSTEP COUNT: "<<cntt;
}
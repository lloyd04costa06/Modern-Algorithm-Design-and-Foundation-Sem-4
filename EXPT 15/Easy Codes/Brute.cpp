#include<iostream>
#include<string>
#define CNT cntt++
using namespace std;
int m,n,cntt=0;


int BruteForce_patternMatching(string text, string pattern)
{
    int j;
    for(int i=0;i<=n-m;i++)
    {
        CNT;
        j=0;   CNT;
        while(j<m && text[i+j]==pattern[j])
        {
              CNT; //for while loop
               j++;  
               CNT; //for j++
        }
        if(j==m)
        {   CNT;
            return i;
        }
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

    int k=BruteForce_patternMatching(text,pattern);
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
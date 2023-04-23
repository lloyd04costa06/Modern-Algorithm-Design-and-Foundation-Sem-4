#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int countt=0;
#define CN countt++
int p[100],w[100];


struct PW
{
    vector <pair<int,int>>S;
}X[100];

void display_pair(vector <pair<int,int>> x)
{
    vector <pair<int,int>> :: iterator it;
    for(it=x.begin();it!=x.end();++it)
    {
       cout<<"{"; cout<<(*it).first;
        cout<<",";
        cout<<(*it).second;cout<<"} ";
    }
    cout<<endl;
}

void purge()
{
    vector <pair<int,int>>:: iterator i;
    vector <pair<int,int>>:: iterator j;

    for(int k=1;k<=n;k++)
    {
      
          for(i=X[k].S.begin(); i!= X[k].S.end();++i)
          {
            CN;
            for(j=i+1; j!= X[k].S.end();++j)
            {  
                CN;   
                if((*i).first<=(*j).first && (*i).second >= (*j).second)
                {CN;X[k].S.erase(i--);j--;CN;}
            }
          }
    }
}


bool PairMatch(vector <pair<int,int>> z, int pp, int ww)
{
    vector <pair<int,int>> :: iterator zi;
    for(zi=z.begin(); zi!=z.end(); ++zi)
    {
        CN;
        if((*zi).first==pp && (*zi).second== ww)
       {CN; return true;CN;}
    }
    return false;
}

void traceBack()
{
        vector <pair<int,int>> :: iterator it;
          vector <pair<int,int>> :: iterator c;
        int solVect[n+1];
        it=max_element(X[n].S.begin(),X[n].S.end());CN; //Find the largest pair
        int pp=(*it).first; int ww=(*it).second;CN;

        cout<<"MAX PROFIT: "<<pp<<endl;
        cout<<"TOTAL WEIGHT OCCUPIED: "<<ww<<endl;

         for(int p=0; p<n;p++)
         {
            solVect[p]=0;
         }
    
        //Start from the n-1 set
        for(int i=n-1;i>=0;i--)
        {
            CN;
          bool status=PairMatch(X[i].S,pp,ww);CN;//check if the set is present or no

          if(status)
          {
            CN;
            solVect[i]=0;CN;
          }
          else
          {
            solVect[i]=1;CN;
            pp=pp - p[i];CN;
             ww=ww - w[i];CN;
          }
        
        }

        cout<<"SOLUTION VECTOR: {";
        for(int p=0; p<n;p++)
        {
            CN;
            cout<<solVect[p];CN;
            if(p!=n-1) cout<<",";
        }cout<<"}"<<endl;
       
}

void Dk()
{
    //S0 initially;
     vector <pair<int,int>> :: iterator it;
    X[0].S.push_back(make_pair(0,0));CN;
    
    int next=1; //next is S1...

    for(int i=0;i<n;i++)
    {
        CN;
        for(it=X[next-1].S.begin();it!=X[next-1].S.end();++it) //Merge previous S1n-1
        {
            CN;
            X[next].S.push_back(make_pair((*it).first,(*it).second));CN;
        }

         for(it=X[next-1].S.begin();it!=X[next-1].S.end();++it) //Calculate the remaining and merge
        {
            CN;
            if(((*it).second)+w[i] > m)
            {CN;continue;}
            X[next].S.push_back(make_pair(((*it).first+p[i]),((*it).second)+w[i]));CN;
        };
        next++;CN;
      
    }

    purge();cout<<endl;CN;
    for(int k=0;k<=n;k++) //Display the subsets
    {
        CN;
          cout<<"S"<<k<<":   ";CN;
        display_pair(X[k].S);CN;
        cout<<endl;
    }
    traceBack();

    
}
int main()
{
 
    cout<<"ENTER NUMBER OF ELEMENTS : ";
    cin>>n;
  
    cout<<"ENTER PROFIT AND WEIGHT OF ELEMENTS: "<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>p[i]>>w[i];
    }
    
    cout<<"ENTER THE BAG CAPACITY : ";
  
    cin>>m;
    
    int x[n+1];
    for(int i=0;i<=n+1;i++)
    {
         x[i]=0;
    }
    Dk();

    cout<<"\nSTEP COUNT: "<<countt;
}